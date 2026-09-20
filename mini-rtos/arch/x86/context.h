#ifndef MINI_RTOS_ARCH_X86_CONTEXT_H
#define MINI_RTOS_ARCH_X86_CONTEXT_H

#include <stddef.h>

#ifdef __cplusplus
extern "C"{
#endif


void *context_init(void *stack_top,void(*entry)(void *arg),void *arg);

void context_switch(void **old_sp,void *new_sp);

#ifdef __cplusplus
}
#endif
#endif


