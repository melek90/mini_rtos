.text
.global context_switch, @function

context_switch:
    movl 4(%esp),%eax
    movl 8(%esp),%edx

    pushl %ebp
    pushl %edi
    pushl %esi
    pushl %ebx


    movl %esp,(%eax)

    popl %ebx
    popl %esi
    popl %edi
    popl %ebp

    ret

.global context_init
.type context_init @function

context_init:
    movl 4(%esp),%eax
    movl 8(%esp),%edx
    movl 12(%esp),%ecx

    andl $-16, %eax
    subl $32,%ecx

    movl $task_trampoline,16(%eax)
    movl $0, 20(%eax)
    movl %edx, 24(%eax)
    movl %ecx, 28(%eax)

    movl $0,0(%eax)
    movl $0,4(%eax)
    movl $0,8(%eax)
    movl $0,12(%eax)

    ret

.type task_trampoline @function
task_trampoline:
    movl 4(%esp), %eax
    movl 8(%esp), %ecx
    pushl %ecx
    call %eax
    addl $4, %esp
    call task_exit
1:  jmp 1b

.section .note.GNU-stack,"",@progbits