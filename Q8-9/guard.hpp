#ifndef GUARD_HPP
#define GUARD_HPP

#include <pthread.h>

class Guard
{
public:
    explicit Guard(pthread_mutex_t &mtx) : mutex(mtx)
    {
        pthread_mutex_lock(&mutex);
    }
    ~Guard()
    {
        pthread_mutex_unlock(&mutex);
    }

private:
    pthread_mutex_t &mutex;
};

#endif // GUARD_HPP
