#include <pthread.h>
#include <stdio.h>

int main() {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_NORMAL);

    pthread_mutex_t m;
    pthread_mutex_init(&m, &attr);

    pthread_mutex_destroy(&m);

    int err = pthread_mutex_lock(&m);
    printf("pthread_mutex_lock returns: %d\n", err);
}