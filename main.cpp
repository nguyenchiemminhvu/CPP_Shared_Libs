#include <unistd.h>
#include <dlfcn.h>
#include <iostream>
#include <map>
#include "example.h"
#include "example.hpp"
#include "example_dl.h"

void * dl_lib;

void __attribute__((constructor)) on_program_startup()
{
    std::cout << "main startup" << std::endl;

    dl_lib = dlopen("libexampledl.so", RTLD_NOW);
    if (dl_lib == NULL)
    {
        std::cout << dlerror() << std::endl;
        exit(-1);
    }
}

void __attribute__((destructor)) on_program_endup()
{
    if (dlclose(dl_lib))
    {
        std::cout << dlerror();
        exit(-1);
    }

    std::cout << "main endup" << std::endl;
}

int main()
{
    Foo();
    Bar();

    void (*lib_func)(void *) = (void (*)(void *))dlsym(dl_lib, "dl_func");
    if (lib_func == NULL)
    {
        std::cout << dlerror() << std::endl;
        return -2;
    }

    lib_func(NULL);

    return 0;
}