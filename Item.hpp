#include<string>
#ifndef ITEM_H
#define ITEM_H
using namespace std;
// fstream ifile;
class item {
    public :
       char  itemId[10];
       char itemName[25];
       char itemCategory[25];
       int  itemStocks;
       float pricePerUnit;
    public:
       void opener(fstream &ifile,char *fileName,ios_base::openmode mode);
       void read() ;
       void pack();
       void unpack();
       void display() ;
       void search() ;
       void removeRecord() ;
       void modify() ;
       void accessing();
       int getQuantity(char* id);
};
#endif