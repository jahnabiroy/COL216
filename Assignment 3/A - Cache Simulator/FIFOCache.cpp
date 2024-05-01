#include "FIFOCache.h"

FIFOCache::FIFOCache(int set, int block, int byte, bool allocate, bool back)
{
    loadHits = 0;
    loadMiss = 0;
    storeHits = 0;
    storeMiss = 0;
    totalCycles = 0;
    sets = log2(set);
    blocks = log2(block);
    wordsPerBlock = byte / 4;
    writeAllocate = allocate;
    writeBack = back;
    cacheImplementation = vector<vector<Block>>(set, vector<Block>(block));
    for (int i = 0; i < set; i++)
    {
        for (int j = 0; j < block; j++)
        {
            Block b(wordsPerBlock, allocate);
            cacheImplementation[i][j] = b;
        }
    }
}

FIFOCache::~FIFOCache()
{
}

void FIFOCache::loadStore(string loads, string addr)
{
    if (loads == "l")
    {
        load(addr);
    }
    else
    {
        store(addr);
    }
}

void FIFOCache::load(string address)
{
    int byteOffset = log2(wordsPerBlock);
    int indexOffset = sets;
    string targetTag = address.substr(0, 30 - byteOffset - indexOffset);
    string index = address.substr(30 - indexOffset - byteOffset, sets);
    bitset<32> idx(index);
    int accessIndex = idx.to_ulong();
    int FIFOIndex = FIFOImplement(accessIndex, targetTag);
    cacheImplementation[accessIndex][FIFOIndex].accessBlock(targetTag, loadHits, loadMiss, totalCycles, mem);
}

void FIFOCache::store(string address)
{
    int byteOffset = log2(wordsPerBlock);
    int indexOffset = sets;
    string targetTag = address.substr(0, 30 - byteOffset - indexOffset);
    string index = address.substr(30 - indexOffset - byteOffset, sets);
    bitset<32> idx(index);
    int accessIndex = idx.to_ulong();
    int FIFOIndex = FIFOImplement(accessIndex, targetTag);
    if (writeAllocate)
    {
        cacheImplementation[accessIndex][FIFOIndex].writeAllocate(targetTag, 0, 0, storeHits, storeMiss, totalCycles, mem, writeBack);
    }
    else
    {
        cacheImplementation[accessIndex][FIFOIndex].writeNoAllocate(targetTag, 0, 0, storeHits, storeMiss, totalCycles, mem, writeBack);
    }
}

int FIFOCache::FIFOImplement(int index, string tag)
{
    for (int i = 0; i < pow(2, blocks); i++)
    {
        if (cacheImplementation[index][i].isValid && (cacheImplementation[index][i].tag == tag))
        {
            q.push(cacheImplementation[index][i]);
            return i;
        }
    }

    if (!q.empty())
        q.pop(); // Remove the oldest element from the queue
    q.push(cacheImplementation[index][pow(2, blocks) - 1]);

    return pow(2, blocks) - 1;
}

void FIFOCache::cacheInfo()
{
    cout << "Total Loads :" << loadHits + loadMiss << endl;
    cout << "Total Stores :" << storeHits + storeMiss << endl;
    cout << "Load Hits :" << loadHits << endl;
    cout << "Load Misses :" << loadMiss << endl;
    cout << "Store Hits :" << storeHits << endl;
    cout << "Store Misses :" << storeMiss << endl;
    cout << "Total Cycles :" << totalCycles << endl;
}