#ifndef LRUCACHE_H
#define LRUCACHE_H
#include <iostream>
#include <cmath>
#include <bitset>
#include "nextLevelMem.h"
#include "line.h"
using namespace std;

class LRUCache
{
public:
    int sets;
    int blocks;
    int wordsPerBlock;
    int indexOffset;
    int byteOffset;
    string tag;
    int loadHits;
    int loadMiss;
    int storeHits;
    int storeMiss;
    int totalCycles;
    bool writeAllocate;
    bool writeBack;
    vector<vector<Block>> cacheImplementation;
    Memory mem;

    LRUCache(int set, int block, int byte, bool allocate, bool back);
    ~LRUCache();
    void loadStore(string loads, string address);
    void load(string address);
    void store(string address);
    int LRUImplement(int idx, string addr);
    void cacheInfo();
};

#endif