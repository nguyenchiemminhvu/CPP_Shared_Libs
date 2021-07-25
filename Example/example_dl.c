#include "example_dl.h"
#include <stdio.h>

void on_lib_startup()
{
    printf("libexampledl.so startup\n");
}

void on_lib_endup()
{
    printf("libexampledl.so endup\n");
}

void dl_func(void *arg)
{
    printf("Call dl_func with dynamic loading technique\n");
}