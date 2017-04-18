#pragma once

#include <iostream>

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

