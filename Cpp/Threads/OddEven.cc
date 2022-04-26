#include <condition_variable>
#include <iostream>
#include <mutex>

#include "ThreadsApi.h"

std::mutex              m;
std::condition_variable c;
uint32_t                counter = 1;

void odd() {
    bool canRun = true;
    while (canRun) {
        std::unique_lock<std::mutex> guard(m);
        c.wait(guard, []() { return (counter % 2 == 1); });
        std::cout << "From Odd : " << counter++ << "\n";
        if (counter > 10) {
            canRun = false;
        }
        guard.unlock();
        c.notify_all();
    }
}

void even() {
    bool canRun = true;
    while (canRun) {
        std::unique_lock<std::mutex> guard(m);
        c.wait(guard, []() { return (counter % 2 == 0); });
        std::cout << "From Even : " << counter++ << "\n";
        if (counter > 10) {
            canRun = false;
        }
        guard.unlock();
        c.notify_all();
    }
}

int main() {
    JoinableThread t1(odd);
    JoinableThread t2(even);
}
