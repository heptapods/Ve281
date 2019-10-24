//
//  SortingAlgorithm.hpp
//  281lab3
//
//  Created by 严欣愉 on 2019/10/6.
//  Copyright © 2019年 yanxinyu. All rights reserved.
//


//bubble sort, insertion sort, selection sort, merge sort, in-place partition quick sort

#include <iostream>
#include <cstdlib>
#include <cassert>

#ifndef SortingAlgorithm_hpp
#define SortingAlgorithm_hpp

void bubbleSort(int a[],int n);
void insertSort(int a[],int n);
void selectSort(int a[], int n);
void mergeSort(int a[], int n);
void quickSort(int a[], int n);

#endif /* SortingAlgorithm_hpp */
