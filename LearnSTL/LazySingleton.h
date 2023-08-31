#pragma once

template<typename T>
class Lazy_Singleton
{
public:
    //单例模式不需要外部构造、拷贝构造、拷贝赋值
    Lazy_Singleton() = delete;
    Lazy_Singleton(const Lazy_Singleton&) = delete;
    Lazy_Singleton& operator= (const Lazy_Singleton&) = delete;

    static T& GetInstance();
};

template <typename T>
T& Lazy_Singleton<T>::GetInstance()
{
    static T Instance;
    return Instance;
}
