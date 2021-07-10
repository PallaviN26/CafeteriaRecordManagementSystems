#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<stdlib.h>

#include "Bill.hpp"
#include "OrderDetails.hpp"
#define fileName "bill.txt"
using namespace std;
fstream billFile;


void Bill:: opener(fstream &ifile,char *filename,ios_base::openmode mode){
    ifile.open(filename,mode);
    if(!ifile){
        cout<<"File not found\n";
        return;
    }
}
void Bill :: read(int id){
    opener(billFile,fileName,ios::app);
    if(!billFile){
        cout<<"\nExit through bill read\n";
        exit(0);
    }
    int m;
    orderDetails od;
    orderId=id;
    totalQuantity=od.calculateTotalQuantity(id);
    float tempAmount=od.calculateTotalAmount(id);
    cout<<"Total amount printing in read: ";
    cout<<tempAmount;
    totalAmount=tempAmount;
    cout<<"Enter the payment Method\n";
    cout<<"1. Cash \t"<<"2. Card\t"<<"3.UPI\nEnter method: ";
    cin >> m;
    switch (m)
    {
    case 1:
        strcpy(method,"Cash") ;
        break;
    case 2:
        strcpy(method,"Card") ;
        break;
    case 3:
        strcpy(method,"UPI") ;
        break;
    default:
        break;
    }
    pack();
    billFile.close();
}

void Bill::pack(){
    billFile<<orderId<<"|"<<totalQuantity<<"|"<<totalAmount<<"|"<<method<<"|#\n";
}
void Bill::display(){
    opener(billFile,fileName,ios::in);
    if(!billFile){
        cout<<"exit through bill display";
        exit(0);
    }
    char buffer[100];
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<"Order Id"<<setw(15)<<"Total Quantity"<<setw(15)<<"Total Amount"<<setw(25)<<"Method"<<endl;
    while(1){
        unpack();
        if(billFile.eof())
            break;
        else{
            cout<<setw(10)<<orderId<<setw(15)<<totalQuantity<<setw(15)<<totalAmount<<setw(25)<<method<<endl;
        }
        // i--;
    }
}

void Bill::unpack(){
    char buffer[75],idBuf[10],quantityBuf[10],amountBuf[10];
    billFile.getline(idBuf,10,'|');
    billFile.getline(quantityBuf,15, '|' );
    billFile.getline(amountBuf,15,'|');
    billFile.getline(method,25,'|');
    orderId=atoi(idBuf);
    totalAmount=atof(amountBuf);
    totalQuantity=atoi(quantityBuf);
    billFile.getline(buffer,75,'#\n');
}

char * Bill::getMethod(int id){
    opener(billFile,fileName,ios::in);
    if(!billFile){
        cout<<"Exit through bill getmethod";
        exit(0);
    }
    while(!billFile.eof()){
        unpack();
        if(orderId==id){
            billFile.close();
            return method;
        }
    }
}

// void item::removeRecord(){
//     //display();
//     opener(billFile,fileName,ios::in);
//     if(!billFile){
//         return;
//     }
//     char id[10];
//     cin.ignore();
//     cout<<"Id of item to search:";
//     gets(id);
//     while (!billFile.eof())
//     {
//         unpack();
//         // cout<<"id:"<<id<<"\titemid"<<itemId<<"\tcomparision"<<strcmp(id,itemId)<<endl;
//         if(strcmp(id,itemId)==0){
//             cout<<"Item Id:"<<itemId<<"\nItem Name: "<<itemName<<"\nItem Category: "<<itemCategory<<"\nItem Stocks: "<<itemStocks<<"\nItem price: "<<pricePerUnit<<endl;
//             return;
//         }
//     }
//     cout<<"Item not found!\n";
// }

// void bill::accessing(){
    
// //   char fileName[25]="item.txt";
//   int n;
//   while (1)
//   {
//     cout<<"1-read\t2-display\t3-search\t4-exit\nEnter choice:";
//     cin>>n;
//     switch (n)
//     {
//         case 1:
//             read();
//             break;
//         case 2:
//             display();
//             break;
//         case 3:
//             removeRecord();//search()
//             break;
//         default:
//             return;
//     }
//     billFile.close();
//   }
// }