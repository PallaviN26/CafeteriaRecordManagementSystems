#include<string>
#ifndef ITEM_H
#define ITEM_H
using namespace std;
class chefs {
   public :
   int  itemId;
   char itemName[50];
   int quantity;
   public:
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