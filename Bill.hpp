#include<string>
#include"base.hpp"
#ifndef ITEM_H
#define ITEM_H
using namespace std;
class Bill : public base{

    public :
      int   orderId;
      int   totalQuantity;
      float totalAmount;
      int   method;
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