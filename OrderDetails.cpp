#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "OrderDetails.hpp"
using namespace std;
int  orderDetails ::  generateOrderId(){
    srand(time(0));
    return rand() % 900;
}
void orderDetails :: read(){
    cout<<"Enter the itemId";
    cin>>itemId;
    cout<<"Enter the quantity";
    cin>>quantity; 
}