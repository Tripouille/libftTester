#include "leak.h"
#include <stdio.h>

t_mlist * mallocList = NULL;

void __wrap_free(void * p)
{
    mallocListRemove(p);
    return (__real_free(p));
}

void * __wrap_malloc(size_t size)
{
    void * p = __real_malloc(size);
    mallocListAdd(p, size);
    return (p);
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
    *actual = __real_malloc(sizeof(t_mlist));
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
        __real_free(actual);
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
            __real_free(prev);
        }
    }
}
