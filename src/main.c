


static long sys_write(int fd , void *buff ,unsigned long bytes){
    long ret;
    __asm__ volatile("syscall"
        : "=a" (ret)
        :  "a"(1L) , "D"((long)fd) , "S"(buff) , "d" (bytes)
        : "rcx", "r11", "memory"
    
    );

    return ret;

}


__attribute__((noreturn));

static void sys_exist(int code){

}




void _start(void){
    static const char msg[] = "hello world\n";
    sys_write(1,msg, sizeof(msg-1));
    sys_exit(0);

}