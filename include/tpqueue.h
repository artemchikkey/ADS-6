// Copyright 2022 NNTU-CS
#include <vector>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <typename T, size_t N>
class TPQueue {
private:
    T data[N];
    size_t size;
public:
    TPQueue() : size(0) {}

    void push(const T& item) {
        if (size == N) {
            std::cerr << "Queue is full!" << std::endl;
            return;
        }

        size_t i = size;
        while (i > 0 && item.prior > data[i - 1].prior) {
            data[i] = data[i - 1];
            i--;
        }
        data[i] = item;
        size++;
    }

    T pop() {
        if (size == 0) {
            std::cerr << "Queue is empty!" << std::endl;
            return T();
        }

        T item = data[0];
        for (size_t i = 1; i < size; ++i) {
            data[i - 1] = data[i];
        }
        size--;
        return item;
    }
};
#endif  
