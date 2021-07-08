#include<string>
#include "base.hpp"
#ifndef ITEM_H
#define ITEM_H
using namespace std;
// fstream ifile;
class Bill : public base{

    public :
      int   orderId;
      int   totalQuantity;
      float totalAmount;
      int   method;
     public:
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