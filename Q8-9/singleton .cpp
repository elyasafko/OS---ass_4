#include <pthread.h>
#include <iostream>

class Singleton
{
protected:
    Singleton()
    {
        pthread_mutex_init(&mutex, NULL);
    }

    virtual ~Singleton()
    {
        pthread_mutex_destroy(&mutex);
    }

public:
    static Singleton *getInstance()
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

    static void destroyInstance()
    {
        pthread_mutex_lock(&getMutex());
        if (instance)
        {
            delete instance;
            instance = nullptr;
        }
        pthread_mutex_unlock(&getMutex());
    }

protected:
    static Singleton *instance;
    static pthread_mutex_t mutex;

private:
    static pthread_mutex_t &getMutex()
    {
        static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
        return mutex;
    }
};

Singleton *Singleton::instance = nullptr;
pthread_mutex_t Singleton::mutex;

class DerivedSingleton : public Singleton
{
public:
    static DerivedSingleton *getInstance()
    {
        return static_cast<DerivedSingleton *>(Singleton::getInstance());
    }

    void doSomething()
    {
        std::cout << "Doing something in DerivedSingleton." << std::endl;
    }

private:
    DerivedSingleton() {}
    friend class Singleton;
};
