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

    void (*lib_func)(void *) = (void (*)(void *))dlsym(dl_lib, "dl_func");
    if (lib_func == NULL)
    {
        std::cout << dlerror() << std::endl;
        return -2;
    }

    lib_func(NULL);

    if (dlclose(dl_lib))
    {
        std::cout << dlerror();
        return -3;
    }

    return 0;
}