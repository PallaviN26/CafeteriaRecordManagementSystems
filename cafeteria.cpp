#include<stdio.h>
class Bill{

    public :
      int   orderId;
      int   totalQuantity;
      float totalAmount;
      int   method;

};
class chefs{
   public :
   int  itemId;
   char itemName[50];
   int quantity;
};
class item{
    public :
       int  itemId;
       char itemName[50];
       char itemCategory[50];
       int  itemStocks;
       float  pricePerUnit;
       
};
class OrderDetails{
    
    public:
      int  orderId;
      int  itemId;
      int   quantity;
      float  amount;
};