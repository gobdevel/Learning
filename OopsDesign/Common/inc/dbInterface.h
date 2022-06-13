#pragma once
#include <vector>

template <typename T>
class Observer {
public:
    virtual void fieldChanged(const T&           source,
                              const std::string& fieldName) = 0;
};

template <typename T>
class Observable {
public:
    void notify(const T& source, const std::string& name) {
        for (auto& o : m_observers) {
            o->fieldChanged(source, name);
        }
    }
    void subscribe(Observer<T>* f) { m_observers.emplace_back(f); }
    void unsubscribe(Observer<T>* f) { m_observers.erase(f); }

private:
    std::vector<Observer<T>*> m_observers;
};

template <typename T>
class Property;

template <typename T>
class PropertyMany : Property<T> {
public:
    explicit PropertyMany(const Property<T>& first, const Property<T>& second)
        : m_first(first), m_second(second) {}

    bool isSatisfied(const T& obj) {
        return (m_first.isSatisfied(obj) && m_second.isSatisfied(obj));
    }

private:
    const Property<T>& m_first;
    const Property<T>& m_second;
};

template <typename T>
class Property {
public:
    virtual bool    isSatisfied(const T&) const = 0;
    PropertyMany<T> operator&&(const Property& other) {
        return PropertyMany<T>{*this, other};
    }
};

template <typename T>
class DbInterface : public Observable<T> {
public:
    using Items  = std::vector<T>;
    using ItemId = std::uint32_t;

    virtual void  addItem(const T&)                              = 0;
    virtual void  removeItem(const T&)                           = 0;
    virtual void  updateItem(const T&)                           = 0;
    virtual Items getItemByProperty(const Property<T>& property) = 0;
    virtual Items getItemById(const ItemId id)                   = 0;
};
