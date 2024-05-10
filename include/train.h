// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TRAIN_H_
#define INCLUDE_TRAIN_H_

class Train {
 private:
    struct Cage {
        bool light;
        Cage *next;
        Cage *prev;
        Cage(bool lightStatus){
         light = lightStatus;
         next = nullptr;
         prev = nullptr;
    };

    Cage *first;
    int countOp;

 public:
    Train();
    ~Train();
    void addCage(bool light);
    int getLength();
    int getOpCount();
};

#endif  // INCLUDE_TRAIN_H_
