#include <iostream>
#include <string>
#include <cmath>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
#include <bitset>
#include <queue>
#include "FIFOCache.h"
#include "LRUCache.h"
using namespace std;

void readFile(istream &input, vector<vector<string>> &details)
{
    string line;

    while (getline(input, line))
    {
        istringstream iss(line);
        string operation;
        string addressHex;
        int size;

        if (iss >> operation >> hex >> addressHex >> size)
        {
            bitset<32> addressBinary(stoul(addressHex, nullptr, 16));
            vector<string> perLine;
            perLine.push_back(operation);
            perLine.push_back(addressBinary.to_string());
            perLine.push_back(to_string(size));
            details.push_back(perLine);
        }
        else
        {
            cerr << "Error parsing line: " << line << endl;
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 7)
    {
        cerr << "Usage: " << argv[0] << "<sets> <blocks> <bytesIneachBlock> <writeHitPolicy> <writeMissPolicy> <replacementPolicy> < <sometracefile>" << endl;
        return 1;
    }

    int sets = stoi(argv[1]);
    int blocks = stoi(argv[2]);
    int bytesIneachBlock = stoi(argv[3]);
    string writeMissPolicy = argv[4];
    string writeHitPolicy = argv[5];
    string replacementPolicy = argv[6];
    bool writeBack = (writeHitPolicy == "write-back");
    bool allocate = (writeMissPolicy == "write-allocate");
    vector<vector<string>> deets;
    readFile(cin, deets);
    if (replacementPolicy == "lru")
    {
        LRUCache l(sets, blocks, bytesIneachBlock, allocate, writeBack);
        for (long unsigned int i = 0; i < deets.size(); i++)
        {
            l.loadStore(deets[i][0], deets[i][1]);
        }
        l.cacheInfo();
    }
    else
    {
        FIFOCache f(sets, blocks, bytesIneachBlock, allocate, writeBack);
        for (long unsigned int i = 0; i < deets.size(); i++)
        {
            f.loadStore(deets[i][0], deets[i][1]);
        }
        f.cacheInfo();
    }
    return 0;
}
