#include <pthread.h>

// Guard class (Scope-based Mutex Lock)
class Guard
{
public:
    // Constructor locks the given mutex
    explicit Guard(pthread_mutex_t &mtx) : mutex(mtx)
    {
        // Lock the mutex to ensure thread-safe access to shared resources
        pthread_mutex_lock(&mutex);
    }

    // Destructor unlocks the mutex
    ~Guard()
    {
        // Unlock the mutex when the Guard object goes out of scope
        pthread_mutex_unlock(&mutex);
    }

private:
    // Reference to the mutex that is being managed
    pthread_mutex_t &mutex;
};
