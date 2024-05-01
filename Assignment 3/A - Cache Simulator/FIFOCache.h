#ifndef FIFOCACHE_H
#define FIFOCACHE_H
#include <iostream>
#include <cmath>
#include <bitset>
#include <queue>
#include "nextLevelMem.h"
#include "line.h"
using namespace std;

class FIFOCache
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
    queue<Block> q;

    FIFOCache(int set, int block, int byte, bool allocate, bool back);
    ~FIFOCache();
    void loadStore(string loads, string addr);
    void load(string address);
    void store(string address);
    int FIFOImplement(int idx, string addr);
    void cacheInfo();
};

#endif