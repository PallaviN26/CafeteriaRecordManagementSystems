#include<string>
#include<fstream>
#ifndef ITEM_H
#define ITEM_H
using namespace std;
class chefs {
   public :
   int  itemId;
   char itemName[50];
   int quantity;
   public:
        void opener(fstream &ifile,char *fileName,ios_base::openmode mode);
       void read() ;
       void pack() ;
       void unpack() ;
       void display() ;
       void search() ;
       void removeRecord() ;
       void modify();
       void accessing();
};
#endif