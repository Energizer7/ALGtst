//
//  main.cpp
//  AlgTest
//
//  Created by Tom Salvet on 18/06/2019.
//  Copyright © 2019 Tom Salvet. All rights reserved.
//
#include <iostream>
using namespace std;
#include "DynamicIntegerSet.hpp"

int main(int argc, const char * argv[])
{
    //Create object
    DynamicIntegerSet set;
    //Add values into set
    for (int i = 0; i < 10; i++) {
        set.Add(i);
    }
    //Print set
    cout << "Display set:";
    set.Print();
    //Display resized size
    cout << "Display elements of the set: "<<set.Count() << endl;
    //add next element
    set.Add(1);
    //Print set
    cout << "Display set:";
    set.Print();
    //add next element
    set.Add(1);
    //Print set
    cout << "Display set:";
    set.Print();
    //Delete 1
    set.Delete(2);
    //Check list
    if (set.IsMember(1)) {
        cout <<"1 Present in set" << endl;
    }
    else {
        cout << "1 Not Present in set" << endl;
        cout << "Display set:";
        set.Print();
    }
}
