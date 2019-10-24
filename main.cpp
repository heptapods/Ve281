//
//  main.cpp
//  281lab3
//
//  Created by 严欣愉 on 2019/10/6.
//  Copyright © 2019年 yanxinyu. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ctime>
#include <cstring>
#include "SortingAlgorithm.hpp"
#include "SelectingAlgorithm.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    srand((unsigned)time(NULL));
    int method;
    int size;
    int order=0;
    int result=0;
    cin>>method>>size;
    int *a=new int[size];
    if (method>=5) {
        cin>>order;
    }
    for (int i=0; i<size; i++) {
        cin>>a[i];
    }
    
    clock_t t;
    t = clock();
    
    switch (method) {
        case 0:
            bubbleSort(a, size);
            break;
        case 1:
            insertSort(a, size);
            break;
        case 2:
            selectSort(a, size);
            break;
        case 3:
            mergeSort(a, size);
            break;
        case 4:
            quickSort(a, size);
            break;
        case 5:
            result=Rselect(a, size, order);
            break;
        case 6:
            result=Rselect(a, size, order);
            break;
        default:
            break;
    }
    if (method<=4) {
        for (int i=0; i<size; i++) {
            cout<<a[i]<<endl;
        }
    } else {
        cout<<"The order-"<<order<<" item is "<<result;
    }
    
    t = clock() - t;
    cout<<"\n__________"<<endl;
    cout<<t<<endl;
    cout<<"___________"<<endl;
    
    
    return 0;
}
