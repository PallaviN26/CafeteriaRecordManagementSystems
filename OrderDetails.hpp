#include<string>
#ifndef ITEM_H
#define ITEM_H
using namespace std;
class OrderDetails{
    
    public:
      int  orderId;
      int  itemId;
      int   quantity;
      float  amount;
};
#endif