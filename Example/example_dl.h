#ifndef __EXAMPLE_DL_H__
#define __EXAMPLE_DL_H__

#if __cplusplus
extern "C" {
#endif

void __attribute__((constructor)) on_lib_startup();
void __attribute__((destructor)) on_lib_endup();

void dl_func(void *arg);

#if __cplusplus
}
#endif

#endif // __EXAMPLE_DL_H__