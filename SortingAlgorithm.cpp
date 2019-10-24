//
//  SortingAlgorithm.cpp
//  281lab3
//
//  Created by 严欣愉 on 2019/10/6.
//  Copyright © 2019年 yanxinyu. All rights reserved.
//

#include "SortingAlgorithm.hpp"
static void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void bubbleSort(int a[],int n)
{
    for (int i=0; i<n-2; i++) {
        for (int j=n-1; j>i; j--) {
            if (a[j-1]>a[j]) {
                swap(a[j-1], a[j]);
            }
        }
    }
}

void insertSort(int a[],int n)
{
    for (int i=1; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (a[i]<a[j]) {
                int temp=a[i];
                for (int k=i; k>j; k--) {
                    a[k]=a[k-1];
                }
                a[j]=temp;
                break;
            }
        }
    }
}

void selectSort(int a[],int n)
{
    for (int i=0; i<n; i++) {
        int min=i;
        for (int j=i+1; j<n; j++) {
            if (a[j]<a[min]) {
                min=j;
            }
        }
        if (min!=i) {
            swap(a[min], a[i]);
        }
    }
}

static void merge(int arr[],int left,int mid,int right)
{
    int *helper_array=new int[right+2];
    int lb=left;
    int rb=mid+1;
    int t=left;
    while (lb<=mid && rb<=right) {
        if (arr[lb]<arr[rb]) {
            helper_array[t++]=arr[lb++];
        }else{
            helper_array[t++]=arr[rb++];
        }
    }
    while (lb<=mid) {
        helper_array[t++]=arr[lb++];
    }
    while (rb<=right) {
        helper_array[t++]=arr[rb++];
    }
    for (int i=left; i<=right; i++) {
        arr[i]=helper_array[i];
    }
    delete[] helper_array;
}

static void mergeSortHelper(int arr[],int left, int right)
{
    int mid=(left+right)/2;
    if (left!=right) {
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int a[], int n)
{
    mergeSortHelper(a, 0, n-1);
}

static int partition(int arr[],int left,int right)
{
    int pivot=arr[left];
    int l=left;
    int r=right;
    while (l<r) {
        while (l<r) {
            if (arr[r]<pivot) {
                break;
            }
            r--;
        }
        while (l<r) {
            if (arr[l]>pivot) {
                break;
            }
            l++;
        }
        swap(arr[l], arr[r]);
    }
    swap(arr[left], arr[l]);
    return l;
}

void quickSortHelper(int a[],int left,int right)
{
    if (left<right) {
        int p=partition(a, left, right);
        quickSortHelper(a, left, p-1);
        quickSortHelper(a, p+1, right);
    }
}

void quickSort(int a[], int n)
{
    quickSortHelper(a, 0, n-1);
}
