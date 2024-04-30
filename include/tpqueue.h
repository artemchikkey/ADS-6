// Copyright 2022 NNTU-CS
#include <vector>
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template <class T>
class TPQueue {
private:
    std::vector<T> data;

public:
    void push(const T& elem) {
        int i = 0;
        for (i = 0; i < data.size(); ++i) {
            if (elem.prior > data[i].prior) {
                break;
            }
        }
        data.insert(data.begin() + i, elem);
    }

    void pop() {
        if (!data.empty()) {
            data.erase(data.begin());
        }
    }

    T front() const {
        return data.front();
    }

    bool empty() const {
        return data.empty();
    }
};
#endif  // INCLUDE_TPQUEUE_H_
