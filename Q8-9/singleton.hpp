#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <pthread.h>

// Abstract Singleton class
class Singleton
{
protected:
    Singleton();
    virtual ~Singleton();

public:
    static Singleton *getInstance();
    static void destroyInstance();

protected:
    static Singleton *instance;
    static pthread_mutex_t mutex;

private:
    static pthread_mutex_t &getMutex();
};

// Example derived class
class DerivedSingleton : public Singleton
{
public:
    static DerivedSingleton *getInstance();
    void doSomething();

private:
    DerivedSingleton();
    friend class Singleton;
};

#endif // SINGLETON_HPP
