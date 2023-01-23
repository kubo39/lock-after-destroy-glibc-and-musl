# glibc vs musl: pthread_mutex_lock after pthread_mutex_destroy

```console
~/dev/c/pthread_mutex_lock$ make
gcc -o glibc_bin app.c -lpthread
./glibc_bin
pthread_mutex_lock returns: 22
musl-gcc -static -o musl_bin app.c
./musl_bin
pthread_mutex_lock returns: 0
```

- glibc: https://github.com/bminor/glibc/blob/ae612c45efb5e34713859a5facf92368307efb6e/nptl/pthread_mutex_destroy.c#L39
- musl: https://github.com/davidlazar/musl/blob/a0e6f336c756d808f8d99ac1f6e383ab38092ad5/src/thread/pthread_mutex_destroy.c#L3-L6
