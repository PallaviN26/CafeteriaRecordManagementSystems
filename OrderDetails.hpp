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
  int flag;//this is for reference of whether there is multiple food item or not, generates id if it is first else not

public:
  orderDetails();
  orderDetails(int f);
  void opener(fstream &ifile,char *filename,ios_base::openmode mode);
  void read();
  void pack() ;
  void unpack() ;
  void display() ;
  void search();
  void removeRecord() ;
  void modify() ;
  void particularOrderAccessing(int id);
  void accessing();
  int generateOrderId();
  int validate(int itemId,int quantity);
  float calculateAmount(int itemId);
  float calculateTotalAmount(int id);
  int calculateTotalQuantity(int id);
};
#endif