#include <iostream>
#include "QuickFind.h"


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


