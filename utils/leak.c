# define _GNU_SOURCE
#include "leak.h"
#include <stdio.h>
#include <unistd.h>
#include <malloc.h>

t_mlist * mallocList = NULL;

void * old_malloc_hook;
void * old_free_hook;

void init_hook(void)
{
    void * old_malloc_hook = __malloc_hook;
    void * old_free_hook = __free_hook;
    __malloc_hook = my_malloc;
    __free_hook = my_free;
}

void * my_malloc(size_t size)
{
    __malloc_hook = old_malloc_hook;
    write(1, "malloc\n", 7);
    void * p = malloc(size);
    mallocListAdd(p, size);
    __malloc_hook = my_malloc;
    return (p);
}

void my_free(void * p)
{
    __free_hook = old_free_hook;
    write(1, "free\n", 5);
    free(p);
    mallocListRemove(p);
    __free_hook = my_free;
}

void mallocListAdd(void * p, size_t size)
{
    t_mlist ** actual = &mallocList;
    t_mlist * prev = NULL;

    while (*actual != NULL)
    {
        prev = *actual;
        actual = &((*actual)->next);
    }
    *actual = malloc(sizeof(t_mlist));
    (*actual)->prev = prev;
    (*actual)->p = p;
    (*actual)->size = size;
    (*actual)->next = NULL;
}

void mallocListRemove(void * p)
{
    t_mlist * actual = mallocList;

    while (actual != NULL && actual->p != p)
        actual = actual->next;
    if (actual != NULL)
    {
        if (actual->next != NULL)
            actual->next->prev = actual->prev;
        if (actual->prev)
            actual->prev->next = actual->next;
        else
            mallocList = actual->next;
        free(actual);
    }
}

void showLeaks(void)
{
    if (mallocList == NULL)
        printf("\e[32mLEAKS.OK");
    else
    {
        printf("\e[31mLEAKS.KO");
        t_mlist * prev = NULL;
        while (mallocList != NULL)
        {
            printf(" [%p : %lu]", mallocList->p, mallocList->size);
            prev = mallocList;
            mallocList = mallocList->next;
            free(prev);
        }
    }
}
