#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include <algorithm>
#include <QFile>
#include <iomanip>
#include <QTime>
#include <fstream>
#include <math.h>
#include <random>
#include <chrono>
#include <vector>
#include <algorithm>
#include <map>
// reference: https://github.com/meysam81/Sparse-Matrix
#include "../Sparse-Matrix/src/SparseMatrix/SparseMatrix.cpp"

using namespace std;

typedef struct Node
{
    int label;
    int newLabel;
    int degree;
} Node;

class Network
{
private:
    int numberOfNodes;
    vector<Node> *nodes;

    SparseMatrix<int> *edges;

    int numberOfRealNetwork; // cA

    int NMI();
public:
    Network();

    bool init(string inputPath);

    bool mainFunc();
};

#endif // NETWORK_H
