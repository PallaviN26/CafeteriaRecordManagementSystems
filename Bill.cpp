#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<stdlib.h>

#include "Bill.hpp"
#define fileName "bill.txt"
using namespace std;
//fstream sfile;


void bill:: opener(fstream &ifile,char *filename,ios_base::openmode mode){
    ifile.open(filename,mode);
    if(!ifile){
        cout<<"File not found\n";
        return;
    }
}
void bill :: read(){
    cout<<"Enter the payment Method\n";
    cout<<"1. Cash \t"<<"2. Card\t"<<"3.UPI\n";
    cin >> method;
}

void item::pack(){
    char buffer[100];
    strcpy(buffer,orderId); 
    strcat(buffer,"|");
    strcat(buffer,totalQuantity);
    strcat(buffer,"|");
    strcat(buffer,totalAmount);
    strcat(buffer,"|");
    strcat(buffer,method);
    strcat(buffer,"|#");
    sfile<<buffer<<"\n";
}
void item::display(){
    opener(sfile,fileName,ios::in);
    if(!sfile){
        
        return;
    }
    char buffer[100];
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<"Order Id"<<setw(25)<<"Total Quantity"<<setw(25)<<"Item Category"<<setw(10)<<"Total amount "<<setw(10)<<"Mode of Payment"<<endl;
    while(1){
        unpack();
        if(sfile.eof())
            break;
        else{
            cout<<setw(10)<<orderId<<setw(25)<<totalQuantity<<setw(25)<<totalAmount<<setw(10)<<itemStocks<<setw(10)<<method<<endl;
        }
        // i--;
    }
}

void item::unpack(){
    char buffer[100];
    sfile.getline(orderId,10,'|');
    sfile.getline(totalQuantity,25, '|' );
    sfile.getline(totalAmount,25,'|');
    sfile.getline(method,1,'|');
    sfile.getline(buffer,100,'#\n');
}
void item::removeRecord(){
    //display();
    opener(sfile,fileName,ios::in);
    if(!sfile){
        return;
    }
    char id[10];
    cin.ignore();
    cout<<"Id of item to search:";
    gets(id);
    while (!sfile.eof())
    {
        unpack();
        // cout<<"id:"<<id<<"\titemid"<<itemId<<"\tcomparision"<<strcmp(id,itemId)<<endl;
        if(strcmp(id,itemId)==0){
            cout<<"Item Id:"<<itemId<<"\nItem Name: "<<itemName<<"\nItem Category: "<<itemCategory<<"\nItem Stocks: "<<itemStocks<<"\nItem price: "<<pricePerUnit<<endl;
            return;
        }
    }
    cout<<"Item not found!\n";
}

void item::accessing(){
    
//   char fileName[25]="item.txt";
  int n;
  while (1)
  {
    cout<<"1-read\t2-display\t3-search\t4-exit\nEnter choice:";
    cin>>n;
    switch (n)
    {
        case 1:
            read();
            break;
        case 2:
            display();
            break;
        case 3:
            removeRecord();//search()
            break;
        default:
            return;
    }
    sfile.close();
  }
}