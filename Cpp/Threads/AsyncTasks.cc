#include <chrono>
#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int someWork() {
    std::this_thread::sleep_for(1s);
    return 100;
}

void asyncExample() {
    std::future<int> task = std::async(someWork);

    // Do some other tasks
    std::this_thread::sleep_for(2s);

    // Will wait till result is available or thread is completed.
    auto ret = task.get();
    std::cout << ret << "\n";
}

void packagedTaskExample() {
    // Create packaged_task
    std::packaged_task<int(void)> task(someWork);

    // Get Future from task
    std::future<int> res = task.get_future();

    // Run task
    task();
    std::cout << "PackagedTask : " << res.get() << "\n";
}

void packagedTaskExampleRunInDifferentThread() {
    // Create packaged_task
    std::packaged_task<int(void)> task(someWork);

    // Get Future from task
    std::future<int> res = task.get_future();

    // Start a separate thread to run task
    auto th = std::thread(std::move(task));

    // Print result in this thread
    std::cout << "PackagedTask : " << res.get() << "\n";
    th.join();
}

void accumulate(std::vector<int>::iterator first,
                std::vector<int>::iterator last,
                std::promise<int>          accumulate_promise) {
    int sum = std::accumulate(first, last, 0);
    accumulate_promise.set_value(sum);  // Notify future
}

void do_work(std::promise<void> barrier) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    barrier.set_value();
}

void promiseExample() {
    // Demonstrate using promise<int> to transmit a result between threads.
    std::vector<int>  numbers = {1, 2, 3, 4, 5, 6};
    std::promise<int> accumulate_promise;
    std::future<int>  accumulate_future = accumulate_promise.get_future();
    std::thread       work_thread(accumulate, numbers.begin(), numbers.end(),
                                  std::move(accumulate_promise));

    // future::get() will wait until the future has a valid result and retrieves
    // it. Calling wait() before get() is not needed
    // accumulate_future.wait();  // wait for result
    std::cout << "result=" << accumulate_future.get() << '\n';
    work_thread.join();  // wait for thread completion

    // Demonstrate using promise<void> to signal state between threads.
    std::promise<void> barrier;
    std::future<void>  barrier_future = barrier.get_future();
    std::thread        new_work_thread(do_work, std::move(barrier));
    barrier_future.wait();
    new_work_thread.join();
}

int main() {
    asyncExample();
    packagedTaskExample();
    packagedTaskExampleRunInDifferentThread();
    promiseExample();
}
