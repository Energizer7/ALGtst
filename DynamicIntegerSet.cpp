//
//  DynamicIntegerSet.cpp
//  AlgTest
//
//  Created by Tom Salvet on 18/06/2019.
//  Copyright © 2019 Tom Salvet. All rights reserved.
//

#include <iostream>
using namespace std;
#include "DynamicIntegerSet.hpp"

//The constructor creates a new object representing an empty set
DynamicIntegerSet::DynamicIntegerSet() {
    item = new int[10];
    size = 10;
    initial_size = 10;
    N = 0;
}
//Destroyer performs proper object de - allocation
DynamicIntegerSet::~DynamicIntegerSet() {
    delete[] item;
}
//Add an element in set
//The method inserts the element x into the given set.
//If the element x already exists in the given set, no action is taken.
void DynamicIntegerSet::Add(const int x) {
    if (IsMember(x)) {
        return;
    }
    if (N < size) {
        item[N] = x;
        N++;
    }
    else {
        int* tempSet;
        tempSet = new int[2*size];
        for (int i = 0; i < N; i++) {
            tempSet[N] = item[i];
        }
        size = 2 * size;
        delete[] item;
        item = tempSet;
        item[N] = x;
        N++;
    }
}
//The method extracts the element x from the given set.
//If element x is not included in the given set, no action is taken.
void DynamicIntegerSet::Delete(const int x) {
    for (int i = 0; i < N; i++) {
        if (item[i] == x) {
            for (int j = i; j < N-1; j++) {
                item[j] = item[j + 1];
            }
            N--;
        }
    }
    if (N < (size / 2) && (size/2)>initial_size) {
        int* tempSet;
        tempSet = new int[size/2];
        for (int i = 0; i < N; i++) {
            tempSet[N] = item[i];
        }
        size = size/2;
        delete[] item;
        item = tempSet;
    }
}

//The method returns true if x is an element of the set, otherwise it returns false.
bool DynamicIntegerSet::IsMember(const int x) const {
    for (int i = 0; i < N; i++) {
        if (item[i] == x) {
            return true;
        }
    }
    return false;
}
//The method returns true if the set is empty, otherwise it returns false
bool DynamicIntegerSet::IsEmpty() const {
    if (N == 0) {
        return true;
    }
    else {
        return false;
    }
}
//The method returns the number of elements of a given set.
int DynamicIntegerSet::Count() const {
    return N;
}
//The method writes the given set to standard output.
void DynamicIntegerSet::Print() const {
    std::cout << "{ ";
    for (int i = 0; i < N; i++) {
        if (i < N - 1) {
            std::cout << item[i] << ", ";
        }
        else {
            std::cout << item[i] << " }" << std::endl;
        }
    }
    
}
