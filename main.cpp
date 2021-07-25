#include <unistd.h>
#include <dlfcn.h>
#include <iostream>
#include "example.h"
#include "example.hpp"
#include "example_dl.h"

int main()
{
    Foo();
    Bar();

    void * dl_lib = dlopen("libexampledl.so", RTLD_NOW);
    if (dl_lib == NULL)
    {
        std::cout << dlerror() << std::endl;
        return -1;
    }

    

    return 0;
}