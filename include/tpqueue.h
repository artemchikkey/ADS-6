// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T, int size>
class TPQueue {
 private:
T data[100] = {};
int start = 0, ind = 0;
 public:
T pop() {
  start = start + 1;
  return data[start - 1];
}
void push(T el) {
  data[ind] = el;
  ind = index + 1;
  for (int l = start; l < ind; l++) {
    for (int i = start; i < ind - 1; i++) {
      if (data[i + 1].prior > data[i].prior) {
        T k = data[i];
        data[i] = data[i + 1];
        data[i + 1] = k;
      }
    }
  }
}
};

struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
