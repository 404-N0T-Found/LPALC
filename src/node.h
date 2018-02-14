#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <QFile>
#include <iomanip>
#include <QTime>
#include <fstream>

#include "network.h"

using namespace std;

class Node
{
private:
    int label;
    int degree;
    int newLabel;

public:
    Node(int label = 0);

    friend class Network; // access private members
};


#endif // NODE_H
