#ifndef LIMITEDQUEUE_LIMITEDQUEUE_H
#define LIMITEDQUEUE_LIMITEDQUEUE_H
#include "../QueueOverflowException/QueueOverflowException.h"
#include "stdexcept"
#include <cstring>
#include <memory>

template<size_t size_temp, typename T, bool Force>
class LimitedQueue {
public:
    static_assert(size_temp > 0, "Size must be greater than 0");
    LimitedQueue() = default;

    LimitedQueue(std::initializer_list<T> list) {
        if(list.size() > size_temp) {
            std::copy(list.begin() + list.size() - size_temp, list.end(), data);
            size_ = size_temp;
        } else {
            std::copy(list.begin(), list.end(), data);
            size_ = list.size();
        }
    }

    void swap(LimitedQueue& other) {
        std::swap(data, other.data);
        std::swap(size_, other.size_);
    }

    LimitedQueue(const LimitedQueue& other) {
        size_ = other.size_;
        std::copy(other.data, other.data + other.size_, data);
    }

    LimitedQueue(LimitedQueue&& other) noexcept {
        swap(other);
    }

    LimitedQueue<size_temp, T, Force>& operator=(const LimitedQueue& other) {
        if (this != &other) {
            LimitedQueue temp(other);
            swap(temp);
        }
        return *this;
    }

    LimitedQueue<size_temp, T, Force>& operator=(LimitedQueue&& other) noexcept {
        if (this != &other) {
            swap(other);
        }
        return *this;
    }

    void push_back(T value) {
        if(full()) {
            if (Force) {
                pop_front();
            } else {
                throw QueueOverflowException<T>("queue is overflowed" ,size_, value);
            }
        }
        data[size_++] = value;

    }

    T pop_front() {
        if(empty()) {
            throw std::out_of_range("queue is empty");
        }
        T tmp = data[0];

        std::memmove(data, data + 1, (size_ - 1) * sizeof(T));
        size_--;


        return tmp;
    }

    T front() {
        if(empty()) {
            throw std::out_of_range("queue is empty");
        }
        return data[0];
    }

    bool empty() {
        return size_ == 0;
    }

    bool full() {
        return size_ == size_temp;
    }

    void clear() {
        size_ = 0;
    }

    size_t size() {
        return size_;

    }


private:
    size_t size_ = 0;
    T data[size_temp];

};


#endif //LIMITEDQUEUE_LIMITEDQUEUE_H
