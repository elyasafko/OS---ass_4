#include <pthread.h>
#include <iostream>

// Abstract Singleton class
class Singleton
{
protected:
    // Protected constructor to prevent direct instantiation
    Singleton()
    {
        // Initialize the mutex for thread safety
        pthread_mutex_init(&mutex, NULL);
    }

    // Destructor to clean up the mutex
    virtual ~Singleton()
    {
        pthread_mutex_destroy(&mutex);
    }

public:
    // Public static method to get the singleton instance
    static Singleton *getInstance()
    {
        // First check without locking (double-checked locking pattern)
        if (!instance)
        {
            // Lock the mutex to ensure only one thread can access this block
            pthread_mutex_lock(&getMutex());
            if (!instance)
            {
                // If instance is still null, create the singleton instance
                instance = new Singleton();
            }
            // Unlock the mutex after instance is created
            pthread_mutex_unlock(&getMutex());
        }
        return instance;
    }

    // Static method to destroy the singleton instance
    static void destroyInstance()
    {
        // Lock the mutex to ensure thread-safe destruction
        pthread_mutex_lock(&getMutex());
        if (instance)
        {
            // Delete the instance and set pointer to null
            delete instance;
            instance = nullptr;
        }
        // Unlock the mutex after destruction
        pthread_mutex_unlock(&getMutex());
    }

protected:
    static Singleton *instance;   // Static instance pointer
    static pthread_mutex_t mutex; // Mutex for thread safety

private:
    // Private method to return a reference to the static mutex
    static pthread_mutex_t &getMutex()
    {
        static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        return mutex;
    }
};

// Initialize static members
Singleton *Singleton::instance = nullptr;
pthread_mutex_t Singleton::mutex;

// Example derived class
class DerivedSingleton : public Singleton
{
public:
    // Public static method to get the derived singleton instance
    static DerivedSingleton *getInstance()
    {
        return static_cast<DerivedSingleton *>(Singleton::getInstance());
    }

    // Example method that does something
    void doSomething()
    {
        std::cout << "Doing something in DerivedSingleton." << std::endl;
    }

private:
    // Private constructor to prevent direct instantiation
    DerivedSingleton() {}

    // Friend class declaration to allow Singleton to access the private constructor
    friend class Singleton;
};
