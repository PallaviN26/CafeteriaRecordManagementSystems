#include<string>
#ifndef ITEM_H
#define ITEM_H
using namespace std;
// fstream ifile;
class Bill{

    public :
      int   orderId;
      int   totalQuantity;
      float totalAmount;
      int   method;
     public:
       void read() ;
       void pack() ;
       void unpack() ;
       void display() ;
       void search() ;
       void removeRecord() ;
       void modify() ;
       void accessing();

};
#endif