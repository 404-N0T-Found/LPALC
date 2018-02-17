#ifndef NETWORK_H
#define NETWORK_H

#include <set>
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

    int numberOfFoundClusters;
    int numberOfRealClusters;

    SparseMatrix<int> *edges;

    // ADD CLUSTERS

    int numberOfRealNetwork; // cA

    int NMI();

    void computeShortestCycle(const int startingPoint,
                              const vector<Node> &neighbors,
                              vector<int> &shortestCycle);

    int shortestPath(const int u, const int v,
                     vector<int> &tmpShortestCycle,
                     const vector<Node> &neighbors);
public:
    Network();

    bool init(const string inputPath, const int numberOfRealClusters);

    bool mainFunc();
};

#endif // NETWORK_H
