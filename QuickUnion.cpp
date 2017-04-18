#include "QuickUnion.h"

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
