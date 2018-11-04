#include "algo.h"
#include <iostream>

QuickUnion::QuickUnion(int arrSize) {
    N = arrSize;
    id = new int[N];
    std::cout << "Quick union algorithm.\n\n";
    for (int i = 0; i < N; i++) {
        id[i] = i; // (double)rand() / (RAND_MAX + 1) * (50 - 10) + 10;
        std::cout << id[i] << ' ';
    }
    std::cout << std::endl;
};

bool QuickUnion::connected(int p, int q) const {
    return QuickUnion::root(p) == QuickUnion::root(q);
}

int QuickUnion::root(int i) const {
    while (i != id[i]) i = id[i];
    return i;
}

void QuickUnion::elem_union(int p, int q) {
    int i = QuickUnion::root(p);
    int j = QuickUnion::root(q);
    id[i] = j;
}


void QuickUnion::print_array() {
    std::cout << "Index: " << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::cout << "Elements: " << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << id[i] << ' ';
    }
}

QuickUnion::~QuickUnion() {
    delete[] id;
}

QuickFind::QuickFind(int arrSize) {
    sz = arrSize;
    id = new int[sz];
    std::cout << "Quick find algorithm.\n\n";
    for (int i = 0; i < sz; i++) {
        id[i] = i; // (double)rand() / (RAND_MAX + 1) * (50 - 10) + 10;
        std::cout << id[i] << ' ';
    }
    std::cout << std::endl;
};

bool QuickFind::connected(int p, int q) {
    return id[p] == id[q];
}

void QuickFind::elem_union(int p, int q) {
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i < sz; i++)
        if (id[i] == pid) id[i] = qid;
}

void QuickFind::print_array() {
    for (int i = 0; i < sz; i++)
        std::cout << id[i] << ' ';
}

QuickFind::~QuickFind() {
    delete[] id;
};

QuickUnionPathCompr::QuickUnionPathCompr(int arrSize) {
    N = arrSize;
    id = new int[N];
    std::cout << "Quick union algorithm.\n\n";
    for (int i = 0; i < N; i++) {
        id[i] = i; // (double)rand() / (RAND_MAX + 1) * (50 - 10) + 10;
        std::cout << id[i] << ' ';
    }
    std::cout << std::endl;
};

bool QuickUnionPathCompr::connected(int p, int q) {
    return QuickUnionPathCompr::root(p) == QuickUnionPathCompr::root(q);
}

int QuickUnionPathCompr::root(int i) {
    while (i != id[i]) {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void QuickUnionPathCompr::elem_union(int p, int q) {
    int i = QuickUnionPathCompr::root(p);
    int j = QuickUnionPathCompr::root(q);
    id[i] = j;
}

void QuickUnionPathCompr::print_array() {
    std::cout << "Index: " << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    std::cout << "Elements: " << std::endl;
    for (int i = 0; i < N; i++) {
        std::cout << id[i] << ' ';
    }
}

QuickUnionPathCompr::~QuickUnionPathCompr() {
    delete[] id;
}

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

