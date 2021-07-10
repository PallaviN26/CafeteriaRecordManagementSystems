#include<string>
#ifndef BILL_H
#define BILL_H
using namespace std;
// fstream ifile;
class Bill{

    public :
      int   orderId;
      int   totalQuantity;
      float totalAmount;
      char method[25];
     public:
       void opener(fstream &ifile,char *filename,ios_base::openmode mode);
       void read(int id) ;
       void pack() ;
       void unpack() ;
       void display() ;
       void search() ;
       void removeRecord() ;
       void modify() ;
       void accessing();
       char * getMethod(int id);
};
#endif