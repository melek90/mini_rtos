#ifndef MINI_RTOS_TASK_H
#define MINI_RTOS_TASK_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C"{
#endif

#define TASK_NAME_MAX_LEN 16
#define TASK_DEFAULT_STACK_SIZE 4096

typedef enum{
    TASK_STATE_READY=0,
    TASk_STATE_RUNNING,
    TASK_STATE_BLOCKED,
    TASK_STATE_SUSPENDED,
    TASK_STATE_TERMINATED

}task_state_t;

typedef uint8_t task_priority_t;
typedef uint32_t task_id_t;
typedef void (*task_entry_t)(void *arg);
typedef struct task_cb{
    task_id_t id;
    char name[TASK_NAME_MAX_LEN];
    void *stack_ptr;
    void *stack_base;
    size_t stack_size;

    task_state_t state;
    task_priority_t priority;
    task_entry_t entry;
    void *arg;
    struct tast_cb *next;
    uint32_t wake_tick;
    

}task_t;


void task_init(void);

task_id_t task_create(const char *name,task_entry_t entry,void *arg,task_priority_t priority,size_t stack_size);

void task_exit(void);
void task_yield(void);
void task_suspend(task_id_t id);
void task_resume(task_id_t id);

void task_sleep(uint32_t ticks);
task_t *task_current(void);
task_t *task_get(task_id_t id);
#ifdef __cplusplus
}
#endif
#endif
