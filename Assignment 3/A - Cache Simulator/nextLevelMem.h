#ifndef NEXTLEVELMEM_H
#define NEXTLEVELMEM_H

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Memory
{
public:
    int n = INT_MAX;
    vector<int> mem;
    Memory();
    ~Memory();
    int memRead(int address);
    void memWrite(int address, int data);
};

#endif