#include "WeightedQuickUnion.h"


#include "WeightedQuickUnion.h"

WeightedQuickUnion::WeightedQuickUnion(int arrSize) {
    N = arrSize;
    id = new int[N];
    branch_deep = new int[N];
    std::fill_n(branch_deep, N, 1); // at initialization, branch deep = 1 for each element
    std::cout << "Weighted quick union algorithm.\n\n";
    for (std::size_t i = 0; i < N; i++) {
        id[i] = static_cast<int>(i); // (double)rand() / (RAND_MAX + 1) * (50 - 10) + 10;
        std::cout << id[i] << ' ';
    }
    std::cout << std::endl;
};

bool WeightedQuickUnion::connected(int p, int q) {
    return WeightedQuickUnion::root(p) == WeightedQuickUnion::root(q);
}

int WeightedQuickUnion::root(int i) {
    while (i != id[i]) i = id[i];
    return i;
}

void WeightedQuickUnion::elem_union(int p, int q) {
    int i = WeightedQuickUnion::root(p);
    int j = WeightedQuickUnion::root(q);
    if (i == j) return;
    if (branch_deep[i] < branch_deep[j]) {
        id[i] = j;
        branch_deep[j] += branch_deep[i];
    } else {
        id[j] = i;
        branch_deep[i] += branch_deep[j];
    }
}


void WeightedQuickUnion::print_array() {
    std::cout << "Index: " << std::endl;
    for (std::size_t i = 0; i < N; i++) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::cout << "Elements: " << std::endl;
    for (std::size_t i = 0; i < N; i++) {
        std::cout << id[i] << ' ';
    }
}

WeightedQuickUnion::~WeightedQuickUnion() {
    delete[] id;
    delete[] branch_deep;
}

