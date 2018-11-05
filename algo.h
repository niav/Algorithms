#ifndef _ALGORITHMS_H
#define _ALGORITHMS_H

#include <cstddef>// for std::size_t
#include "utils.h"

class QuickUnion {
private:
    int N;
    int *id;

public:
    QuickUnion(int arrSize);

    bool connected(int p, int q) const;

    void elem_union(int p, int q);

    int root(int i) const;

    void print_array();

    ~QuickUnion();
};

class QuickFind {
private:
    int sz;
    int *id;

public:
    QuickFind(int arrSize);

    bool connected(int p, int q);

    void elem_union(int p, int q);

    void print_array();

    ~QuickFind();
};

class QuickUnionPathCompr {
private:
    int N;
    int *id;
public:
    QuickUnionPathCompr(int N);

    bool connected(int p, int q);

    void elem_union(int p, int q);

    int root(int i);

    void print_array();

    ~QuickUnionPathCompr();
};

class WeightedQuickUnion {
private:
    int N;
    int *id{nullptr};
    int *branch_deep{nullptr};

public:
    WeightedQuickUnion(int arrSize);

    bool connected(int p, int q);

    void elem_union(int p, int q);

    int root(int i);

    void print_array();

    ~WeightedQuickUnion();
};


template<typename T>
size_t binarySearchRecursive(const T *sortedArray, size_t low, size_t hi, const T &value) {
    if (sortedArray == nullptr || low >= hi) return -1;
    size_t mid = low + (hi - low) / 2;
    T current = sortedArray[mid];
    if (current > value) return binSearch(sortedArray, low, mid, value);
    else if (current < value) return binSearch(sortedArray, mid + 1, hi, value);
    return mid;
}

template<typename T>
size_t binarySearch(const T *sortedArray, const size_t size, const T &value) {
    if (sortedArray == nullptr || size == 0) return -1;
    size_t low{0}, hi{size}, mid;
    do {
        mid = low + (hi - low) / 2;
        T current = sortedArray[mid];
        if (current > value) {
            hi = mid - 1;
        } else if (current < value) {
            low = mid + 1;
        } else return mid;
    } while (low < hi);
    return -1;
}

template<typename T>
void insertionSort(T *array, const std::size_t size) {//SLOW ALGORITHM
    if (array == nullptr || !size) return;
    for (std::size_t i = 0; i < size; ++i) {
        for (std::size_t j = i; j > 0; --j) {
            if (array[j - 1] > array[j])
                swap(array[j - 1], array[j]);
            else break;
        }
    }
}

#endif //_ALGORITHMS_H
