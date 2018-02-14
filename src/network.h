#ifndef NETWORK_H
#define NETWORK_H

#include "node.h"
class Node; // forward declaration

#include "../Sparse-Matrix/src/SparseMatrix/SparseMatrix.cpp"

class Network
{
private:
    int numberOfNodes;
    Node* nodes;

    SparseMatrix<int> *edges;
public:
    Network();

    bool init(string inputPath);
};

#endif // NETWORK_H
