#include "LRUCache.h"

LRUCache::LRUCache(int set, int block, int byte, bool allocate, bool back)
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
    mem = Memory();
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

LRUCache::~LRUCache()
{
}

void LRUCache::loadStore(string loads, string addr)
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

void LRUCache::load(string address)
{
    int byteOffset = log2(wordsPerBlock);
    int indexOffset = sets;
    string targetTag = address.substr(0, 30 - byteOffset - indexOffset);
    string index = address.substr(30 - indexOffset - byteOffset, indexOffset);
    bitset<32> idx(index);
    int accessIndex = idx.to_ulong();
    int LRUIndex = LRUImplement(accessIndex, targetTag);
    cacheImplementation[accessIndex][LRUIndex].frequency++;
    cacheImplementation[accessIndex][LRUIndex].accessBlock(targetTag, loadHits, loadMiss, totalCycles, mem);
}

void LRUCache::store(string address)
{
    int byteOffset = log2(wordsPerBlock);
    int indexOffset = sets;
    string targetTag = address.substr(0, 30 - byteOffset - indexOffset);
    string index = address.substr(30 - indexOffset - byteOffset, indexOffset);
    string wordIndex = address.substr(30 - byteOffset, byteOffset);
    bitset<32> idx(index);
    int accessIndex = idx.to_ulong();
    int LRUIndex = LRUImplement(accessIndex, targetTag);
    cacheImplementation[accessIndex][LRUIndex].frequency++;
    if (writeAllocate)
    {
        cacheImplementation[accessIndex][LRUIndex].writeAllocate(targetTag, 0, 0, storeHits, storeMiss, totalCycles, mem, writeBack);
    }
    else
    {
        cacheImplementation[accessIndex][LRUIndex].writeNoAllocate(targetTag, 0, 0, storeHits, storeMiss, totalCycles, mem, writeBack);
    }
}

int LRUCache::LRUImplement(int index, string tag)
{
    int temp = INT_MAX;
    int emptyIndex = 0;
    for (int i = 0; i < pow(2, blocks); i++)
    {
        if (cacheImplementation[index][i].isValid && (cacheImplementation[index][i].tag == tag))
        {
            return i;
        }
        else if (cacheImplementation[index][i].frequency < temp)
        {
            temp = cacheImplementation[index][i].frequency;
            emptyIndex = i;
        }
    }

    return emptyIndex;
}

void LRUCache::cacheInfo()
{
    cout << "Total Loads :" << loadHits + loadMiss << endl;
    cout << "Total Stores :" << storeHits + storeMiss << endl;
    cout << "Load Hits :" << loadHits << endl;
    cout << "Load Misses :" << loadMiss << endl;
    cout << "Store Hits :" << storeHits << endl;
    cout << "Store Misses :" << storeMiss << endl;
    cout << "Total Cycles :" << totalCycles << endl;
}