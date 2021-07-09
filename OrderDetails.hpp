#include <string>
#ifndef ORDERDETAILS_H
#define ITEM_H
#define ORDERDETAILS_H
using namespace std;
class orderDetails {
public:
  int orderId;
  int itemId;
  int quantity;
  float amount;

public:
  void read();
  void pack() ;
  void unpack() ;
  void display() ;
  void search();
  void removeRecord() ;
  void modify() ;
  void accessing();
  int generateOrderId();
};
#endif