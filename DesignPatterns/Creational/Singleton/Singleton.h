#ifndef __SINGLETON_H__
#define __SINGLETON_H__

#include <functional>

template <typename T>
class Singleton {
public:
    using SingletonDerive =
        Singleton<T>;  // use only friend SingletonDerive in derive class

    template <typename... Args>
    static T& getInstance(Args&&... args) {
        static T s_instance(std::forward<Args>(args)...);
        return s_instance;
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&)                 = delete;
    Singleton& operator=(Singleton&&) = delete;

protected:
    Singleton() = default;
};

#endif
