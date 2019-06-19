//
//  DynamicIntegerSet.hpp
//  AlgTest
//
//  Created by Tom Salvet on 18/06/2019.
//  Copyright © 2019 Tom Salvet. All rights reserved.
//

#ifndef DynamicIntegerSet_hpp
#define DynamicIntegerSet_hpp

#include <stdio.h>

class DynamicIntegerSet {
public:
    //The constructor creates a new object representing an empty set
    DynamicIntegerSet();
    //Destroyer performs proper object de - allocation
    ~DynamicIntegerSet();
    //Add an element in set
    void Add(const int x);
    //The method inserts the element x into the given set.If the element x already exists in the given set, no action is taken.
    void Delete(const int x);
    //The method extracts the element x from the given set.If element x is not included in the given set, no action is taken.
    bool IsMember(const int x) const;
    //The method returns true if x is an element of the set, otherwise it returns false.
    bool IsEmpty() const;
    //The method returns true if the set is empty, otherwise it returns false
    int Count() const;
    //The method returns the number of elements of a given set.
    void Print() const;
private:
    int *item;
    int size;
    int initial_size;
    int N;
};

#endif /* DynamicIntegerSet_hpp */
