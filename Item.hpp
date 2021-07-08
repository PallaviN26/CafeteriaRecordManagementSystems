#include<string>
#include "base.hpp"
#ifndef ITEM_H
#define ITEM_H
using namespace std;
// fstream ifile;
class item : public base{
    public :
       char  itemId[10];
       char itemName[25];
       char itemCategory[25];
       char  itemStocks[10];
       char  pricePerUnit[10];
    public:
       void opener(fstream &ifile,char *fileName,ios_base::openmode mode);
       void read() override;
       void pack() override;
       void unpack() override;
       void display() override;
       void search() override;
       void removeRecord() override;
       void modify() override;
       void accessing() override;
};
#endif