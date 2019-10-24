//
//  SelectingAlgorithm.cpp
//  281lab3
//
//  Created by 严欣愉 on 2019/10/7.
//  Copyright © 2019年 yanxinyu. All rights reserved.
//

#include "SelectingAlgorithm.hpp"
#include "SortingAlgorithm.hpp"

static void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

static int partition(int arr[],int left,int right,int p)
{
    swap(arr[left], arr[p]);
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

static int RselectHelper(int a[],int left,int right,int order)
{
    int n=right-left+1;
    if (left==right) {
        return a[left];
    }else{
        int pivot=rand()%n+left;
        int p=partition(a, left, right,pivot);
        if (p==order) {
            return a[order];
        }else if (order<p){
            return RselectHelper(a, left, p-1, order);
        }else{
            return RselectHelper(a, p+1, right, order);
        }
    }
}

int Rselect(int a[],int n,int order)
{
    return RselectHelper(a, 0, n-1, order);
}


int DselectHelper(int a[],int left,int right,int order)
{
    int n=right-left+1;
    int m=n%5==0?n/5:n/5+1;
    if (left>=right) {
        return a[left];
    }else{
        int *c=new int[m];
        for (int i=0; i<m; i++) {
            if (i<m-1) {
                insertSort(a+left+5*i, 5);
                c[i]=a[left+5*i+2];
            }else{
                insertSort(a+left+5*i, n-5*(m-1));
                c[i]=left+5*i+2<right?a[left+5*i+2]:a[right];
            }
        }
        
        int pivot=DselectHelper(c, 0, m-1, m/2);
        
        delete [] c;
        int pivot_index=left;
        while (pivot_index<right && a[pivot_index]!=pivot) {
            pivot_index++;
        }
        
        
        int p=partition(a, left, right,pivot_index);

        if (p==order) {
            return a[order];
        }else if (order<p){
            return DselectHelper(a, left, p-1, order);
        }else{
            return DselectHelper(a, p+1, right, order);
        }
    }
}

int Dselect(int a[],int n,int order)
{
    return DselectHelper(a, 0, n-1, order);
}
