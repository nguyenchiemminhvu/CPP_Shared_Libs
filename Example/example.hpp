#ifndef __EXAMPLE_HPP__
#define __EXAMPLE_HPP__

#include <sys/types.h>
#include <sys/errno.h>
#include <unistd.h>
#include <iostream>

#if __cplusplus
extern "C" {
#endif

void Bar();

#if __cplusplus
}
#endif

#endif // __EXAMPLE_HPP__