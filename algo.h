#ifndef _ALGORITHMS_H
#define _ALGORITHMS_H

#include <cstddef>

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
std::size_t binarySearch(T *sortedArray, std::size_t low, std::size_t hi, const T &value);

#endif //_ALGORITHMS_H
