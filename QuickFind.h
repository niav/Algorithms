#pragma once

#include <iostream>

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

