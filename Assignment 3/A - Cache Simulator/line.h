#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include "nextLevelMem.h"
using namespace std;

class Block
{
public:
    int size;      // is the size of the block -> like no of words
    bool allocate; // to decide write allocate or write no allocate
    string tag = "";
    bool isValid;
    bool isDirty;
    vector<int> data;
    int frequency;

    Block();
    Block(int sz, bool writeAllocate);
    ~Block();
    void accessBlock(string adr, int &loadHits, int &loadMiss, int &totalCycles, Memory &mem);
    void writeAllocate(string adr, int wordIndex, int writeData, int &storeHits, int &storeMiss, int &totalCycles, Memory &mem, bool writeBack);
    void writeNoAllocate(string adr, int wordIndex, int writeData, int &storeHits, int &storeMiss, int &totalCycles, Memory &mem, bool writeBack);
};

#endif // LINE_H