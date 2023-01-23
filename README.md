# glibc vs musl: pthread_mutex_lock after pthread_mutex_destroy

```console
~/dev/c/lock-after-destroy-glibc-and-musl$ make
gcc -o glibc_bin app.c -lpthread
./glibc_bin
pthread_mutex_lock returns: 22
musl-gcc -static -o musl_bin app.c
./musl_bin
pthread_mutex_lock returns: 0
```

## How `pthread_mutex_destroy` implemented?

### glibc

- https://github.com/bminor/glibc/blob/ae612c45efb5e34713859a5facf92368307efb6e/nptl/pthread_mutex_destroy.c#L39

```c
int
___pthread_mutex_destroy (pthread_mutex_t *mutex)
{
(snip...)
  /* Set to an invalid value.  Relaxed MO is enough as it is undefined behavior
     if the mutex is used after it has been destroyed.  But you can reinitialize
     it with pthread_mutex_init.  */
  atomic_store_relaxed (&(mutex->__data.__kind), -1);

  return 0;
}
```

### musl
- https://github.com/davidlazar/musl/blob/a0e6f336c756d808f8d99ac1f6e383ab38092ad5/src/thread/pthread_mutex_destroy.c#L3-L6

```c
int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
	return 0;
}
```
