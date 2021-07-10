#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "OrderDetails.hpp"
#include "Item.hpp"
using namespace std;

item itemobj;
fstream orderFile;
#define fileName "order.txt"
void orderDetails :: opener(fstream &ifile,char *filename,ios_base::openmode mode){
    ifile.open(filename,mode);
    if(!ifile){
        cout<<"File not found\n";
        return;
    }
}

orderDetails::orderDetails(int f):flag(f){}

int  orderDetails ::  generateOrderId(){
    srand(time(0));
    return rand() % 900;
}
void orderDetails :: read(){
    opener(orderFile,fileName,ios::app);
    if(!orderFile){
        
        return;
    }

    cout<<"Enter the itemId";
    cin>>itemId;
    cout<<"Enter the quantity";
    cin>>quantity; 
    int availQuantity = validate(itemId,quantity);
    if(availQuantity != 0 )
    {
        cout<<"The available quantity is only "<< availQuantity <<endl;
        cout<<"Sorry cant make the order !!! \n";
        orderFile.close();
        return;
    }
     amount=calculateAmount(itemId);
    pack();
    itemobj.modify(itemId,quantity * (-1) );
    orderFile.close();
    
}
int orderDetails :: validate(int itemId , int quantity){

    if(itemobj.getQuantity(itemId) < quantity ){
        cout<< itemobj.getQuantity(itemId);
        return quantity;
    }
    else
        return 0;   
}
void orderDetails :: pack(){
    orderFile<<orderId<<"|"<<itemId<<"|"<<quantity<<"|"<<amount<<"|#\n";
    
}
float  orderDetails :: calculateAmount(int itemId){
  return  itemobj.getPrice(itemId) * quantity;
}
void orderDetails::unpack(){
    char buffer[50],oidBuf[10],iidBuf[10],quantitybuf[10],amountBuf[10];
    orderFile.getline(oidBuf,10,'|');
    orderFile.getline(iidBuf,10,'|');
    orderFile.getline(quantitybuf,10,'|');
    orderFile.getline(amountBuf,10,'|');
    orderId=atoi(oidBuf);
    itemId=atoi(iidBuf);
    quantity=atoi(quantitybuf);
    amount=atof(amountBuf);
}
void orderDetails::particularOrderAccessing(){
    opener(orderFile,fileName,ios::in);
    if(!orderFile){
        return;
    }
    int currOrderId=orderId;
    // cout<<setw(25);
    // cout<<orderId<<endl;//for bill 
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<"Item Id"<<setw(25)<<"Item Name"<<setw(10)<<"Quantity"<<setw(25)<<"PricePerUnit"<<setw(10)<<"Amount"<<endl;
    while(1){
        unpack();
        if(orderFile.eof())
            break;
        else if(currOrderId==orderId){
            cout<<setw(10)<<itemId<<setw(25)<<itemobj.itemName<<setw(10)<<quantity<<setw(25)<<itemobj.pricePerUnit<<setw(10)<<amount<<endl;
        }
    }
    orderFile.close();
}

