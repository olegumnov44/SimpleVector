#pragma once

#include <array>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std::string_literals;

template <typename T, size_t N>
class StackVector {
public:

    using Iterator = typename std::array<T, N>::iterator;
    using ConstIterator = typename std::array<const T, N>::iterator;

    explicit StackVector(size_t a_size = 0)
        //: array_(std::array<T, N>{})
        : capacity_(N)
        , size_(a_size)
    {
        if (size_ > N) {
            throw std::invalid_argument("a_size is biggier then capacity!"s);
        }
    }

    T& operator[](size_t index) {
        return array_[index];
    }

    const T& operator[](size_t index) const {
        return array_[index];
    }

    Iterator begin() { return array_.begin(); }

    Iterator end() {
        return array_.begin() + size_;
    }

    ConstIterator begin() const { return array_.cbegin(); }

    ConstIterator end() const { return array_.cend(); }


    size_t Size() const { return size_; }

    size_t Capacity() const { return capacity_; }


    void PushBack(const T& value) {
        try {
            if (capacity_ == size_) {
                throw std::overflow_error("overflow error!"s);
            }
            else {
                array_[size_] = value;
                ++size_;
                return;
            }
        }
        catch (std::overflow_error& e) {
            throw;
        }
    }

    T PopBack() {
        if (size_ == 0) {
            throw std::underflow_error("empty array"s);
        }
        T tmp = array_[size_ - 1];
        --size_;
        return tmp;
    }

private:
    std::array<T, N> array_;
    size_t capacity_;
    size_t size_;
};
