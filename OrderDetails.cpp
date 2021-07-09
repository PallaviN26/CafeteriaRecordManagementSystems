#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "OrderDetails.hpp"
#include "Item.hpp"
using namespace std;
#define ITEM_H

int  orderDetails ::  generateOrderId(){
    srand(time(0));
    return rand() % 900;
}
void orderDetails :: read(){
    cout<<"Enter the itemId";
    cin>>itemId;
    cout<<"Enter the quantity";
    cin>>quantity; 
    int availQuantity = validate(itemId,quantity);
    if(availQuantity != 0 )
    {
        cout<<"The available quantity is only "<< availQuantity <<endl;
        cout<<"Sorry cant make the order !!! \n";
        return;
    }
    pack();
}
int orderDetails :: validate(int itemId , int quantity){

    if(1)
        return 1;
    else
        return 0;   
}
void orderDetails :: pack(){
    
}