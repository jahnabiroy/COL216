#include "nextLevelMem.h"

Memory::Memory()
{
    mem = vector<int>(1, 0);
}

Memory::~Memory()
{
}

int Memory::memRead(int address)
{
    if (address > n || address < 0)
    {
        __throw_range_error("Out of Range");
    }
    return mem[0];
}

void Memory::memWrite(int address, int data)
{
    if (address > n || address < 0)
    {
        __throw_range_error("Out of Range");
    }
    mem[0] = data;
}