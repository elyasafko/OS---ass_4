#include <iostream>
#include <pthread.h>

#include "singleton .cpp"
#include "guard.cpp"

int main()
{
    DerivedSingleton *singleton = DerivedSingleton::getInstance();
    singleton->doSomething();

    // Demonstrating the use of Guard
    pthread_mutex_t exampleMutex = PTHREAD_MUTEX_INITIALIZER;

    {
        Guard guard(exampleMutex);
        // Critical section
        std::cout << "Inside critical section" << std::endl;
    }
    // Mutex is automatically unlocked when guard goes out of scope

    DerivedSingleton::destroyInstance();
    return 0;
}
