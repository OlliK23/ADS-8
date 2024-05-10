// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
    if (first != nullptr) {
        Cage *current = first->next;
        while (current != first) {
            Cage *next = current->next;
            delete current;
            current = next;
        }
        delete first;
    }
}

void Train::addCage(bool light) {
    Cage *newCage = new Cage(light);
    if (first == nullptr) {
        first = newCage;
        first->next = first->prev = first;
    } else {
        Cage *last = first->prev;
        last->next = newCage;
        newCage->prev = last;
        newCage->next = first;
        first->prev = newCage;
    }
}

int Train::getLength() {
    if (first == nullptr) {
        return 0; }
    Cage *current = first;
    bool initialState = current->light;
    int length = 1;
    current->light = !initialState;
    while (true) {
        current = current->next;
        countOp++;
        if (current->light != initialState) {
            break;
        } else {
            length++;
            current->light = !initialState;
        }
    }
    Cage *reset = first;
    for (int i = 0; i < length; ++i) {
        reset->light = initialState;
        reset = reset->next;
    }
    return length;
}

int Train::getOpCount() {
    return countOp;
}
