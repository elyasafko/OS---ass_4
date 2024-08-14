#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <pthread.h>

class Singleton
{
protected:
    Singleton();
    virtual ~Singleton();
    static Singleton *instance;
    static pthread_mutex_t mutex;

public:
    static Singleton *getInstance();
    static void destroyInstance();

private:
    static pthread_mutex_t &getMutex();
};

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
