#include "leak.hpp"
#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>
#include <dlfcn.h>

//std::vector<ptr> mallocList;

void * malloc(size_t size) throw()
{
    (void)size;
    void *(*libc_malloc)(size_t) = (void *(*)(size_t))dlsym(RTLD_NEXT, "malloc");
    write(1, "mallocu\n", 8);
    std::ostringstream ss; ss << size; write(1, ss.str().c_str(), ss.str().size());
    void * p = libc_malloc(size);
    //mallocListAdd(p, size);
    return (p);
}

void free(void * p) throw()
{
    void (*libc_free)(void*) = (void (*)(void *))dlsym(RTLD_NEXT, "free");
    write(1, "free\n", 5);
    libc_free(p);
   // mallocListRemove(p);
}

void mallocListAdd(void * p, size_t size)
{
    (void)p; (void)size;
}

void mallocListRemove(void * p)
{
    (void)p;
}

void showLeaks(void)
{
    //std::vector<int> mallocList;
    //void (*libc_free)(void*) = (void (*)(void *))dlsym(RTLD_NEXT, "free");
    //if (mallocList.size())
        //write(1, "ok", 2);//printf("\e[32mLEAKS.OK");
    //else
    {
        write(1, "ko", 2); //printf("\e[31mLEAKS.KO");
        //printf(" [%p : %lu]", mallocList->p, mallocList->size);
    }
}
