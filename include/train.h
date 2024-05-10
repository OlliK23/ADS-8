// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
  struct Cage {
    bool light;
    Cage *next;
    Cage *prev;
    explicit Cage(bool lightStatus) : light(lightStatus), next(nullptr), prev(nullptr) {}
    };
  };
  int countOp;
  Cage *first;
 public:
  Train();
  ~Train();
  void addCage(bool light);
  int getLength();
  int getOpCount();
};

#endif  // INCLUDE_TRAIN_H_
