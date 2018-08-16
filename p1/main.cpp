#include<iostream>
#include<cstdlib>
#include"sort.h"

void (*const f[])(int *arr, unsigned int n) = {bubblesort, insertionsort, selectionsort, mergesort, quicksort_ex, quicksort_in};

void print(int *arr, const unsigned int n);

int main(int argc, char const *argv[]) {
    unsigned int fn_index, size;
    // assume the input is always legal
    cin >> fn_index >> size;
    int *arr = new int [size];
    for (unsigned int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    f[fn_index](arr, size);
    print(arr, size);
    delete[] arr;
    return 0;
}

void print(int *arr, const unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
}
