#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <math.h>
#include "Chefs.hpp"

#define fileName "chef.txt"
using namespace std;
fstream chefFile,chefTempFile;

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

// int chefs::search(int id){
//     opener(chefTempFile,fileName,ios::in);
//     if(!chefTempFile){
//         cout<<"Exit through search in chef\n";
//         exit(0);
//     }
//     while (!chefTempFile.eof())
//     {
//         unpack();
//         if(id==itemId){
//             return 1;
//         }
//     }
//     return 0;
//     chefTempFile.close();
// }
void chefs:: unpack(){
    char buffer[75],idBuf[10],quantityBuf[10];
    chefFile.getline(idBuf,10,'|');
    chefFile.getline(itemName,25,'|');
    chefFile.getline(quantityBuf,10,'|');
    chefFile.getline(buffer,75,'#\n');
    itemId=atoi(idBuf);
    quantity=atoi(quantityBuf);
}

void chefs ::display()
{
    opener(chefFile, fileName, ios::in);
    if (!chefFile)
    {
        return;
    }
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<"Item Id"<<setw(25)<<"Item Name"<<setw(10)<<"Quantity"<<endl;
    while(1){
        if(chefFile.eof())
        break;
        unpack();
        cout << setw(10) << itemId << setw(25) << itemName << setw(10) << quantity << endl;
    }
    chefFile.close();
}
void chefs::read(){
    opener(chefFile,fileName,ios::app);
    if(!chefFile){
        cout<<"Exit through chef pack";
        exit(0);
    }
    pack();
}
void chefs :: modify(int id,int num){
    item itemObj;
    int pos;
    opener(chefFile,fileName,ios::in|ios::binary|ios::out);
    if(!chefFile){
        cout<<"Exit through modify chef\n";
        exit(0);
    }
    while(!chefFile.eof()){
        pos = chefFile.tellg();
        unpack();
            if(itemId == id){
                //strcpy(itemName,itemObj.getItemName(id));
                quantity += num;

            }
    }
}
void chefs::accessing()
{
    int choice;
    int id,num;
    while (1)
    {
        cout<<"1. View orders to prepare \t2. Update prepared order\t3.Return \n";
        cout<< "Enter your choice \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            display();
            break;
        
        case 2: 
            cout<<"Enter item id";
            cin >> id;
            cout<<"Enter quantity of item prepared";
            cin >> num;
            modify(id,(-1*num));
            break;
        default:
            return;
        }
    }
}