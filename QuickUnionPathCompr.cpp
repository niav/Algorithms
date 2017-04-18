#include "QuickUnionPathCompr.h"


#include "QuickUnionPathCompr.h"

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
