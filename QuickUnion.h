#pragma once

#include <iostream>

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

