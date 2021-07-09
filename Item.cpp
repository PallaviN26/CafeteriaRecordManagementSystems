#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<typeinfo>

#include "Item.hpp"
#define fileName "item.txt"
using namespace std;
fstream sfile;


void item :: opener(fstream &ifile,char *filename,ios_base::openmode mode){
    ifile.open(filename,mode);
    if(!ifile){
        cout<<"File not found\n";
        return;
    }
}
void item::read(){
    opener(sfile,fileName,ios::app);
    if(!sfile){
        
        return;
    }
    cout<<"Enter details:\n";
    cout<<"Enter item id: ";
    cin>>itemId;
    cin.ignore();
    cout<<"Enter food item name: ";
    gets( itemName);
    cout<<"Enter item category: ";
    gets(itemCategory);
    cout<<"Enter item stock: ";
    cin>>itemStocks;
    cout<<"Enter price per unit: ";
    cin>>pricePerUnit;
    pack();
}

void item::pack(){
    sfile<<itemId<<"|"<<itemName<<"|"<<itemCategory<<"|"<<itemStocks<<"|"<<pricePerUnit<<"|#\n";
}
void item::display(){
    opener(sfile,fileName,ios::in);
    if(!sfile){
        
        return;
    }
    char buffer[100];
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<"Item Id"<<setw(25)<<"Item Name"<<setw(25)<<"Item Category"<<setw(10)<<"Stock"<<setw(10)<<"Price"<<endl;
    while(1){
        unpack();
        if(sfile.eof())
            break;
        else if((itemStocks)>0){
            cout<<setw(10)<<itemId<<setw(25)<<itemName<<setw(25)<<itemCategory<<setw(10)<<itemStocks<<setw(10)<<pricePerUnit<<endl;
        }
        // i--;
    }
}

void item::unpack(){
    char buffer[100];
    char stackBuf[10],priceBuf[10],idBuf[10];
    sfile.getline(idBuf,10,'|');
    sfile.getline(itemName,25, '|' );
    sfile.getline(itemCategory,25,'|');
    sfile.getline(stackBuf,10,'|');
    sfile.getline(priceBuf,10,'|');
    itemId=atoi(idBuf);
    itemStocks=atoi(stackBuf);
    pricePerUnit=atof(priceBuf);
    sfile.getline(buffer,100,'#\n');
   
}
void item::removeRecord(){
    //display();
    opener(sfile,fileName,ios::in);
    if(!sfile){
        return;
    }
    int id;
    cin.ignore();
    cout<<"Id of item to search:";
    cin>>(id);
    while (!sfile.eof())
    {
        unpack();
        // cout<<"id:"<<id<<"\titemid"<<itemId<<"\tcomparision"<<strcmp(id,itemId)<<endl;
        if((id==itemId)){
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
    cout<<"1-Add an item\t2-Current Menu\t3-Search for a food by item id\t4-exit\nEnter choice:";
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
int item::getQuantity(int id){
    opener(sfile,fileName,ios::in);
    if(!sfile){
        return 0;
    }
    cin.ignore();
    while (!sfile.eof())
    {
        unpack();
        if((id==itemId)){
           return itemStocks;
        }
    }
    return 0;
}