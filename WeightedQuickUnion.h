#pragma once

#pragma once

#include <iostream>

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



