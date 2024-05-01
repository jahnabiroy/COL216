#include "line.h"
#include <fstream>

std::ofstream outputFile("output.txt", std::ios::app);

Block::Block()
{
}

Block::Block(int sz, bool writeAllocate)
{
    size = sz;
    allocate = writeAllocate;
    data = vector<int>(sz, 0);
    isValid = false;
    isDirty = false;
    frequency = 0;
    tag = "";
}
Block::~Block()
{
}

void Block::accessBlock(string targetTag, int &loadHits, int &loadMiss, int &totalCycles, Memory &mem)
{
    if (tag == targetTag && isValid)
    {
        outputFile << "load hit" << endl;
        loadHits++;
        totalCycles++;
        return;
    }
    else if (!isValid)
    {
        for (int i = 0; i < size; i++)
        {
            totalCycles += 100;
            data[i] = mem.memRead(i);
        }
        totalCycles++;
        loadMiss++;
        tag = targetTag;
        outputFile << "load miss" << endl;
        isValid = true;
        return;
    }
    else if (isDirty)
    {
        for (int i = 0; i < size; i++)
        {
            totalCycles += 100;
            mem.memWrite(i, data[i]);
        }
        isDirty = false;
    }
    loadMiss++;
    outputFile << "load miss" << endl;
    for (int i = 0; i < size; i++)
    {
        totalCycles += 100;
        data[i] = mem.memRead(i);
    }
    isDirty = false;
    tag = targetTag;
    totalCycles++;
}

void Block::writeAllocate(string targetTag, int wordIndex, int writeData, int &storeHits, int &storeMiss, int &totalCycles, Memory &mem, bool writeBack)
{
    if (tag == targetTag && isValid)
    {
        data[wordIndex] = writeData; // should write data into the address basically to cache
        totalCycles++;
        if (!writeBack)
        {
            for (int i = 0; i < size; i++)
            {
                mem.memWrite(i, data[i]);
                totalCycles += 100;
            }
        } // to memory
        else
        {
            isDirty = true;
        }
        outputFile << "store hit" << endl;
        storeHits++;
        return;
    }
    else if (!isValid)
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = mem.memRead(i);
            totalCycles += 100;
        }
        if (!writeBack)
        {
            for (int i = 0; i < size; i++)
            {
                mem.memWrite(i, data[i]);
                totalCycles += 100;
            }
        }
        outputFile << "store miss" << endl;
        storeMiss++;
        totalCycles++;
        tag = targetTag;
        isValid = true;
        return;
    }
    else if (isDirty)
    {
        for (int i = 0; i < size; i++)
        {
            mem.memWrite(i, data[i]);
            totalCycles += 100;
        }
        isDirty = false;
    }
    storeMiss++;
    totalCycles++;
    outputFile << "store miss" << endl;
    for (int i = 0; i < size; i++)
    {
        data[i] = mem.memRead(i);
        totalCycles += 100;
    }
    tag = targetTag;
    data[wordIndex] = writeData;
    if (!writeBack)
    {
        for (int i = 0; i < size; i++)
        {
            mem.memWrite(i, data[i]);
            totalCycles += 100;
        }
    }
    else
    {
        isDirty = true;
    }
    return;
}

void Block::writeNoAllocate(string targetTag, int wordIndex, int writeData, int &storeHits, int &storeMiss, int &totalCycles, Memory &mem, bool writeBack)
{
    if (tag == targetTag && isValid)
    {
        data[0] = writeData; // should write data into the address basically to cache
        outputFile << "store hit" << endl;
        storeHits++;
        totalCycles++;
        if (!writeBack)
        {
            for (int i = 0; i < size; i++)
            {
                mem.memWrite(i, data[i]);
                totalCycles += 100;
            }
        } // to memory
        else
        {
            isDirty = true;
        }
        return;
    }
    else if (!isValid)
    {
        outputFile << "store miss" << endl;
        for (int i = 0; i < size; i++)
        {
            if (i == wordIndex)
            {
                mem.memWrite(i, writeData);
            }
            else
            {
                mem.memWrite(i, data[i]);
            }
            totalCycles += 100;
        }
        tag = targetTag;
        isValid = true;
        storeMiss++;
        return;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            mem.memWrite(i, data[i]);
            totalCycles += 100;
        }
    }
}
