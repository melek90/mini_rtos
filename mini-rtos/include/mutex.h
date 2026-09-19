#ifndef MINI_RTOS_MUTEX_H
#define MINI_RTOS_MUTEX_H
#include <stdint.h>
#include <stdbool.h>
#include "task.h"

#ifdef __cplusplus
extern "C" {
#endif


typedef struct mutex
{
    bool locked;
    task_t *owner;
    task_t *wait_queu;
    task_priority_t owner_orig_priority;

} mutex_t;

void mutex_init(mutex_t *m);
void mutext_locked(mutex_t *m);
void mutex_trylock(mutex_t *m);
void mutex_unlock(mutex_t *m);
void mutext_is_locked(const mutex_t *m);

#ifdef __cplusplus;
}
#endif

#endif

