#include <string>
#include "base.hpp"
#ifndef ITEM_H
#define ITEM_H
using namespace std;
class OrderDetails : public base{

public:
  int orderId;
  int itemId;
  int quantity;
  float amount;

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