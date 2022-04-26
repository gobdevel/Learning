#ifndef __THREADS_API_H__
#define __THREADS_API_H__

#include <stdexcept>
#include <thread>

// Makes Thread instance joinable
class ThreadGuard {
public:
    explicit ThreadGuard(std::thread th) : m_thread(std::move(th)) {
        if (!m_thread.joinable()) {
            throw std::logic_error("No Thread !!!");
        }
    }
    ~ThreadGuard() { m_thread.join(); }

    ThreadGuard(const ThreadGuard&) = delete;
    ThreadGuard& operator=(const ThreadGuard&) = delete;

private:
    std::thread m_thread;
};

// Joinable Thread replaces std::thread
class JoinableThread {
public:
    JoinableThread() noexcept = default;

    template <typename Callable, typename... Args>
    explicit JoinableThread(Callable&& func, Args&&... args)
        : m_thread(std::forward<Callable>(func), std::forward<Args>(args)...) {}

    explicit JoinableThread(std::thread th) noexcept {
        m_thread = std::move(th);
    }

    JoinableThread(JoinableThread&& other) noexcept
        : m_thread(std::move(other.m_thread)) {}

    JoinableThread& operator=(JoinableThread&& other) {
        if (joinable()) {
            join();
        }
        m_thread = std::move(other.m_thread);
        return *this;
    }

    JoinableThread& operator=(std::thread other) {
        if (joinable()) {
            join();
        }
        m_thread = std::move(other);
        return *this;
    }

    ~JoinableThread() noexcept {
        if (joinable()) {
            join();
        }
    }

    void detach() { m_thread.detach(); }
    void join() { m_thread.join(); }

    void swap(JoinableThread& other) noexcept { m_thread.swap(other.m_thread); }
    std::thread::id    get_id() const noexcept { return m_thread.get_id(); }
    std::thread&       as_thread() noexcept { return m_thread; }
    const std::thread& as_thread() const noexcept { return m_thread; }

private:
    bool joinable() const noexcept { return m_thread.joinable(); }

    std::thread m_thread;
};

#endif
