#ifndef __OBSERVER_PATTERN_H__
#define __OBSERVER_PATTERN_H__

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Observer {
public:
    virtual void fieldChanged(T& source, const std::string& fieldName) = 0;
};

template <typename T>
class Observable {
public:
    void notify(T& source, const std::string& name) {
        for (auto& o : m_observers) {
            o->fieldChanged(source, name);
        }
    }
    void subscribe(Observer<T>* f) { m_observers.emplace_back(f); }
    void unsubscribe(Observer<T>* f) { m_observers.erase(f); }

private:
    std::vector<Observer<T>*> m_observers;
};

class Student : public Observable<Student> {
public:
    Student(int age) : m_age(20) {}
    int  getAge() const noexcept { return m_age; }
    void setAge(int age) {
        if (m_age != age) {
            m_age = age;
            notify(*this, "age");
        }
    }

private:
    int m_age;
};

class TestPersonObserver : public Observer<Student> {
public:
    void fieldChanged(Student& p, const std::string& fieldName) override {
        std::cout << "Student's Age changed : " << p.getAge() << "\n";
    }
};

#endif
