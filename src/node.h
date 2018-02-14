#ifndef NODE_H
#define NODE_H

#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>



using namespace std;

class Node
{
private:
    int label;
    int degree;
    int newLabel;

public:
    Node(int label = 0);

};


#endif // NODE_H
