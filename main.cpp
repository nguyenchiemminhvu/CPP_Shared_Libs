#include <unistd.h>
#include <dlfcn.h>
#include <iostream>
#include "shared_libs.h"
#include "example.h"
#include "example.hpp"

int main()
{
    Foo();
    Bar();

    return 0;
}