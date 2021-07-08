#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<stdlib.h>

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
    cin.ignore();
    cout<<"Enter item id: ";
    gets(itemId);
    cout<<"Enter food item name: ";
    gets( itemName);
    cout<<"Enter item category: ";
    gets(itemCategory);
    cout<<"Enter item stock: ";
    gets(itemStocks);
    cout<<"Enter price per unit: ";
    gets(pricePerUnit);
    pack();
}

void item::pack(){
    char buffer[100];
    strcpy(buffer,itemId); 
    strcat(buffer,"|");
    strcat(buffer,itemName);
    strcat(buffer,"|");
    strcat(buffer,itemCategory);
    strcat(buffer,"|");
    strcat(buffer,itemStocks);
    strcat(buffer,"|");
    strcat(buffer,pricePerUnit);
    strcat(buffer,"#");
    sfile<<buffer<<"\n";
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
        else{
            cout<<setw(10)<<itemId<<setw(25)<<itemName<<setw(25)<<itemCategory<<setw(10)<<itemStocks<<setw(10)<<pricePerUnit<<endl;
        }
        // i--;
    }
}

void item::unpack(){
    char buffer[100];
    sfile.getline(itemId,10,'|');
    sfile.getline(itemName,25, '|' );
    sfile.getline(itemCategory,25,'|');
    sfile.getline(itemStocks,10,'|');
    sfile.getline(pricePerUnit,10,'|');
    sfile.getline(buffer,100,'\n');
}
void item::deleteItem(){
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

void item::itemAccessing(){
    
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
            deleteItem();//search()
            break;
        default:
            return;
    }
    sfile.close();
  }
}