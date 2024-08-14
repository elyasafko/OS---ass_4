#include "singleton.hpp"
#include <iostream>

// Initialize static members
Singleton *Singleton::instance = nullptr;
pthread_mutex_t Singleton::mutex;

Singleton::Singleton()
{
    pthread_mutex_init(&mutex, NULL);
}

Singleton::~Singleton()
{
    pthread_mutex_destroy(&mutex);
}

Singleton *Singleton::getInstance()
{
    if (!instance)
    {
        pthread_mutex_lock(&getMutex());
        if (!instance)
        {
            instance = new Singleton();
        }
        pthread_mutex_unlock(&getMutex());
    }
    return instance;
}

void Singleton::destroyInstance()
{
    pthread_mutex_lock(&getMutex());
    if (instance)
    {
        delete instance;
        instance = nullptr;
    }
    pthread_mutex_unlock(&getMutex());
}

pthread_mutex_t &Singleton::getMutex()
{
    static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
    return mutex;
}

// DerivedSingleton methods
DerivedSingleton::DerivedSingleton() {}

DerivedSingleton *DerivedSingleton::getInstance()
{
    return static_cast<DerivedSingleton *>(Singleton::getInstance());
}

void DerivedSingleton::doSomething()
{
    std::cout << "Doing something in DerivedSingleton." << std::endl;
}
