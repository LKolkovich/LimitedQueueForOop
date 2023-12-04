#include <iostream>

#include "LimitedQueue/LimitedQueue.h"



void test_push_and_pop() {

    const int max_size = 3;
    LimitedQueue<max_size, int, false> q;

    std::cout << "push and pop of " << max_size << " elements in queue\n";

    for(int i = 0; i < max_size; i++) {
        q.push_back(i);
        std::cout << i << " pushed to queue and it`s size is " << q.size() << '\n';
    }

    for(int i = 0; i < max_size; i++) {
        std::cout << "poped element = " << q.pop_front() << " queue size is " << q.size() << '\n';
    }

    std::cout << "is queue empty now? - " << (q.empty() ? "yes" : "no") << '\n';
}

void test_clear_and_front() {
    const int max_size = 3;
    LimitedQueue<max_size, int, false> q;

    std::cout << "push of " << max_size << " elements in queue and clear it\n";

    for(int i = 0; i < max_size; i++) {
        q.push_back(i);
        std::cout << i << " pushed to queue and it`s size is " << q.size() << '\n';
    }

    std::cout << "first element is " << q.front() << '\n';

    q.clear();

    std::cout << "is queue empty now? - " << (q.empty() ? "yes" : "no") << '\n';
}

void make_queue_using_iter_list() {
    std::cout << "creating queue using iteration list\n";

    const int max_size = 3;
    LimitedQueue<max_size, int, false> q = {1,2,3};

    for(int i = 0; i < max_size; i++) {
        std::cout << "first element = " << q.pop_front() << " queue size is " << q.size() << '\n';
    }

    LimitedQueue<max_size, int, false> qq = {1,2,3,4,5,6,7,8,9};

    for(int i = 0; i < max_size; i++) {
        std::cout << "first element = " << qq.pop_front() << " queue size is " << qq.size() << '\n';
    }

}

void push_to_full_queue() {
    std::cout << "push to full forced queue\n";
    const int max_size = 3;

    LimitedQueue<max_size, int, true> q_forced = {1,2,3};
    q_forced.push_back(4);
    std::cout << "first element in queue is " << q_forced.front() << '\n';


    std::cout << "push to full not forced queue\n";

    LimitedQueue<max_size, int, false> q_not_forced = {1,2,3};
    try {
        q_not_forced.push_back(4);
    } catch (QueueOverflowException<int> &e) {
        std::cout << "trying to push to not forced queue makes exception\n";
        std::cout << "pushed value was " << e.data() << "\nsize of queue was " << e.size() << '\n';
        std::cout << "first element of queue is still " << q_not_forced.front() << '\n';
        std::cout << "message of exception:\n" << e.what();
    }
}

int main() {
    test_push_and_pop();
    std::cout << "\n\n\n";
    test_clear_and_front();
    std::cout << "\n\n\n";
    make_queue_using_iter_list();
    std::cout << "\n\n\n";
    push_to_full_queue();

}
