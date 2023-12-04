#ifndef LIMITEDQUEUE_QUEUEOVERFLOWEXCEPTION_H
#define LIMITEDQUEUE_QUEUEOVERFLOWEXCEPTION_H

#include <iostream>
#include <string>
#include <sstream>
#include <exception>

template<typename T>
class QueueOverflowException : public std::runtime_error  {
public:
    QueueOverflowException(const std::string& msg, size_t size, T data) : std::runtime_error(msg), size_(size), data_(data) {};

    size_t size() {return size_;}

    T data() {return data_;}

private:
    size_t size_;
    T data_;
};


#endif //LIMITEDQUEUE_QUEUEOVERFLOWEXCEPTION_H
