#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <math.h>
#include "Chefs.hpp"

#define fileName "chef.txt"
using namespace std;
fstream chefFile;
char buffer[85];

void chefs::opener(fstream &ifile, char *filename, ios_base::openmode mode)
{
    ifile.open(filename, mode);
    if (!ifile)
    {
        cout << "File not found\n";
        return;
    }
}

int chefs ::hash(int id)
{                      // range 0 - 5 or 1 - 6
    int tableSize = 6; //  number of buckets
    float constant = 0.789213;
    return floor(tableSize * frac(id * constant));
}
float chefs ::frac(float x)
{
    return x - floor(x);
}
void chefs ::pack()
{
    chefFile << itemId << "|" << itemName << "|" << quantity << "|";
}
void chefs::insert(int extra)
{
    opener(chefFile, fileName, ios ::in | ios ::binary | ios ::out);
    if (!chefFile)
    {
        cout << "Exit through chef pack";
        return;
    }
    int addr = hash(itemId);
    cout << addr;
    int bucketSize = 6;
    int noOfBuckets = 5;
    int pos = addr * (sizeof(chefs) + 4) * noOfBuckets;
    chefFile.seekp(pos, ios::beg);
    char ch = chefFile.peek();
    if (ch != '#')
    {
        int i = 0;
        char dummy[10];
        while (ch != '#' && i < bucketSize)
        {
            chefFile.getline(dummy, 10, '|');
            int id = atoi(dummy);
            if (id != itemId)
            {
                cout<<"Byee"<<chefFile.tellp();
                pos += sizeof(chefs) + 4;
                i++;
                chefFile.seekp(pos, ios::beg);
                ch = chefFile.peek();
                cout<<"Hello"<<chefFile.tellp();
            }
            else
            {
                unpack();
                quantity += extra;
                pack();
                chefFile.close();
                return;
            }
        }
        if (i == bucketSize)
        {
            cout << " Bucket overflow";
            chefFile.close();
            return;
        }
    }
    else
        pack();

    chefFile.close();
}
void chefs::insertDummy()
{
    opener(chefFile, fileName, ios ::in | ios ::binary | ios ::out);
    if (!chefFile)
    {
        cout << "Exit through chef pack";
        return;
    }
    for (int i = 0; i < 30; i++)
    {
        chefFile.seekp(i * (sizeof(chefs) + 4), ios::beg);
        for (int j = 0; j < sizeof(chefs) + 3; j++)
            chefFile << "#";
        chefFile << endl;
    }
}

void chefs::unpack()
{
    char buffer[75], idBuf[10], quantityBuf[10];
    chefFile.getline(idBuf, 10, '|');
    chefFile.getline(itemName, 25, '|');
    chefFile.getline(quantityBuf, 10, '|');
    chefFile.getline(buffer, 75, '#\n');
    itemId = atoi(idBuf);
    quantity = atoi(quantityBuf);
    cout << itemId << quantity;
}

void chefs ::display()
{
    opener(chefFile, fileName, ios::in);
    if (!chefFile)
    {
        return;
    }
    cout << setiosflags(ios::left);
    cout << setw(10) << "Item Id" << setw(25) << "Item Name" << setw(10) << "Quantity" << endl;
    while (!chefFile.eof())
    {
        unpack();
        cout << setw(10) << itemId << setw(25) << itemName << setw(10) << quantity << endl;
    }
    chefFile.close();
}

void chefs ::modify()
{
    int id, num;
    cout << "Enter item id";
    cin >> id;
    cout << "Enter quantity of item prepared";
    cin >> num;
    int pos;
    opener(chefFile, fileName, ios::in | ios::binary | ios::out);
    while (!chefFile.eof())
    {
        pos = chefFile.tellg();
        unpack();
        if (chefFile)
        {
            if (itemId == id)
            {
                chefFile.seekp(pos);
                quantity -= num;
                pack();
                break;
            }
        }
    }
    chefFile.close();
}
void chefs::accessing()
{
    int choice;
    while (1)
    {
        cout << "1. View orders to prepare \t2. Update prepared order \n";
        cout << "Enter your choice \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            display();
            break;

        case 2:
            modify();
            break;
        default:
            return;
        }
    }
}