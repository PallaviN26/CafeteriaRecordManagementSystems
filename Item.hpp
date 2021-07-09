#include<string>
#ifndef ITEM_HPP
#define ITEM_HPP
using namespace std;
// fstream ifile;
class item {
    public :
       int  itemId;
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
       int getQuantity(int id);
       float getPrice(int id);
      };
#endif