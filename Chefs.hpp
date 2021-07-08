#include<string>
#include"base.hpp"
#ifndef ITEM_H
#define ITEM_H
using namespace std;
class chefs :public base{
   public :
   int  itemId;
   char itemName[50];
   int quantity;
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