#include<iostream>
#include<cstdlib>
#include"sort.h"

void bubblesort(int *arr, const unsigned int n) {
    for (unsigned int i = n - 2; i > 0; i--) {
        for (unsigned int j = 0; j <= i; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionsort(int *arr, const unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
    //  version 1
        // int j = i - 1;
        // int temp = arr[i];
        // while (arr[j] > arr[i] && j >= 0) {
        //     arr[j+1] = arr[j];
        //     j--;
        // }
        // arr[++j] = temp;
    //  version 2
        int j = i;
        while (arr[j] < arr[j-1] && j > 0) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}


void selectionsort(int *arr, const unsigned int n) {
    for (unsigned int i = 0; i < n-1; i++) {
        for (unsigned int j = i; j < n; j++) {
            if (arr[j] < arr[i]) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

void merge(int *arr, int *L, int *R, unsigned int left, unsigned int right) {
    unsigned int i = 0, j = 0, k = 0;
    while (i<left && j<right) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }
    while (i<left) arr[k++] = L[i++];
    while (j<right) arr[k++] = R[j++];
}

void mergesort(int *arr, const unsigned int n) {
    int *L, *R;
    unsigned int mid, i;
    if (n < 2) return;
    mid = n/2;
    L = new int [mid];
    R = new int [n-mid];
    for (unsigned int m = 0; m < mid; m++) {
        L[m] = arr[m];
    }
    for (unsigned int m = 0; m < n-mid; m++) {
        R[m] = arr[mid+m];
    }
    mergesort(L, mid);
    mergesort(R, n-mid);
    merge(arr, L, R, mid, n-mid);
    delete[] L;
    delete[] R;
}

void quicksort(int *arr, const unsigned int n, unsigned int (*f)(int *, const unsigned int)) {
    if (n < 2) return;
    unsigned int pivot = rand() % n;
    swap(arr[0], arr[pivot]);
    pivot = f(arr, n);
    quicksort(arr, pivot, f);
    quicksort(arr+pivot+1, n-pivot-1, f);
}

unsigned int partition_ex(int *arr, unsigned int n) {
    int *temp = new int [n];
    unsigned int i = 0, k = 0, j = n-1;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[0]) {
            temp[k++] = arr[i];
        }
        else temp[j--] = arr[i];
    }
    temp[k] = arr[0];
    for (unsigned int m = 0; m < n; m++) {
        arr[m] = temp[m];
    }
    delete[] temp;
    return k;
}

unsigned int partition_in(int *arr, unsigned int n) {
    unsigned int i = 1, j = n-1;
    while (1) {
        while (i < n-1 && arr[i] < arr[0]) i++;
        while (j > 0 && arr[j] >= arr[0]) j--;
        if(i < j) swap(arr[i], arr[j]);
        else break;
    }
    swap(arr[0], arr[j]);
    return j;
}

void quicksort_ex(int *arr, const unsigned int n) {
    quicksort(arr, n, partition_ex);
}

void quicksort_in(int *arr, const unsigned int n) {
    quicksort(arr, n, partition_in);
}
