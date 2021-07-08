#include<string>
#ifndef ITEM_H
#define ITEM_H
using namespace std;
// fstream ifile;
class item{
    public :
       char  itemId[10];
       char itemName[25];
       char itemCategory[25];
       char  itemStocks[10];
       char  pricePerUnit[10];
    public:
       void opener(fstream &ifile,char *fileName,ios_base::openmode mode);
       void read();
       void pack();
       void unpack();
       void display();
       void search();
       void deleteItem();
       void modifyItem();
       void itemAccessing();
};
#endif