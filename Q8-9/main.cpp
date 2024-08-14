#include <iostream>
#include <pthread.h>

// Include the Singleton and Guard implementations
#include "singleton.hpp"
#include "guard.hpp"

int main()
{
    // Get the Singleton instance of DerivedSingleton
    DerivedSingleton *singleton = DerivedSingleton::getInstance();
    singleton->doSomething(); // Call a method on the singleton instance

    // Demonstrating the use of Guard
    pthread_mutex_t exampleMutex = PTHREAD_MUTEX_INITIALIZER;

    {
        // Guard automatically locks the mutex when it's created
        Guard guard(exampleMutex);

        // Critical section starts here
        std::cout << "Inside critical section" << std::endl;

        // Mutex will remain locked until guard goes out of scope
    } // Guard's destructor unlocks the mutex here

    // The mutex is now unlocked, and other threads can access the critical section

    // Properly destroy the Singleton instance
    DerivedSingleton::destroyInstance();

    return 0;
}
