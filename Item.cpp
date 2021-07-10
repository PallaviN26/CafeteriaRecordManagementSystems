#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include<stdlib.h>
#include<typeinfo>

#include "Item.hpp"
#include "OrderDetails.hpp"
#define fileName "item.txt"
using namespace std;
fstream itemFile;


void item :: opener(fstream &ifile,char *filename,ios_base::openmode mode){
    ifile.open(filename,mode);
    if(!ifile){
        cout<<"File not found\n";
        return;
    }
}
void item::read(){
    opener(itemFile,fileName,ios::app);
    if(!itemFile){
        
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
    itemFile.close();
}

void item::pack(){
    itemFile<<itemId<<"|"<<itemName<<"|"<<itemCategory<<"|"<<itemStocks<<"|"<<pricePerUnit<<"|#\n";
}
void item::display(){
    opener(itemFile,fileName,ios::in);
    if(!itemFile){
        
        return;
    }
    char buffer[100];
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<"Item Id"<<setw(25)<<"Item Name"<<setw(25)<<"Item Category"<<setw(10)<<"Stock"<<setw(10)<<"Price"<<endl;
    while(1){
        unpack();
        if(itemFile.eof())
            break;
        else if((itemStocks)>0){
            cout<<setw(10)<<itemId<<setw(25)<<itemName<<setw(25)<<itemCategory<<setw(10)<<itemStocks<<setw(10)<<pricePerUnit<<endl;
        }
        // i--;
    }
    itemFile.close();
}

void item::unpack(){
    char buffer[100];
    char stackBuf[10],priceBuf[10],idBuf[10];
    itemFile.getline(idBuf,10,'|');
    itemFile.getline(itemName,25, '|' );
    itemFile.getline(itemCategory,25,'|');
    itemFile.getline(stackBuf,10,'|');
    itemFile.getline(priceBuf,10,'|');
    itemId=atoi(idBuf);
    itemStocks=atoi(stackBuf);
    pricePerUnit=atof(priceBuf);
    itemFile.getline(buffer,100,'#\n');
}
int  item::search(int id){
    //display();
    opener(itemFile,fileName,ios::in);
    if(!itemFile){
        return -1;
    }
    cin.ignore();
    int count = 0;
    while (!itemFile.eof())
    {
        unpack();
        if((id==itemId)){
            return count++;
        }
        count++;
    }
    cout<<"Item not found!\n";
    return 0;
    itemFile.close();
}
void item :: modify(int id , int stocks){
   int pos ;
   opener(itemFile,fileName,ios::in | ios :: binary | ios :: out );
   while(!itemFile.eof()){
       pos = itemFile.tellg();
       unpack();
       if(itemFile){
           if(id == itemId){
               itemStocks += stocks;
               itemFile.seekp(pos);
               pack();
               break;
           }
            
       }
   }
   itemFile.close();
}

void item::accessing(){
//   char fileName[25]="item.txt";
  int mainchoice;
  int takeOrderChoice;
  int viewOrderChoice;
  orderDetails od(0);
  while (1)
  {
      menu:
    cout<<"1-Menu\t2-Take order\t3-exit\nEnter choice:";
    cin>>mainchoice;
    switch (mainchoice)//second switch(menu switch)
    {
        case 1:
            display();
            break;
        takeOrder:
        case 2:
            if(od.flag==0)
                {
                    od.orderId=od.generateOrderId();
                    od.flag=1;
                }
            od.read();

            while(1){
                //orderProgress:
                cout<<"\n1.View order\t2.Continue Ordering\t3.Return\nEnter choice: ";
                cin>>takeOrderChoice;
                switch (takeOrderChoice)
                {
                case 1:
                    od.particularOrderAccessing();
                    
                    while (1)
                    {
                        cout<<"\n1.Modify Order\t2.Generate Bill\t3.Continue Ordering\t4.Cancel Order\nEnter choice: ";
                        cin>>viewOrderChoice;
                        switch (viewOrderChoice)
                        {
                        case 1:
                            cout<<"Modify order";
                            //od.modify();
                            break;
                        case 2:
                            cout<<"Bil generate\n";
                            break;
                        case 3:
                            goto takeOrder;
                            break;
                        default:
                            cout<<"Order cancelled so modify order file and to main menu\n";
                            goto menu;//goto takeOrder;
                            break;
                        }
                    }
                    break;
                case 2:
                    goto takeOrder;
                    break;
                default:
                    goto menu;
                }
            }
            break;
        default:
            return;
    }
    itemFile.close();
  }
}
int item::getQuantity(int id){
    opener(itemFile,fileName,ios::in);
    int stocks = 0;
    if(!itemFile){
        cout<<"Exit from getquantity";
        // return -1;
        exit(0);
    }
    while (!itemFile.eof())
    {
        unpack();
        if((id==itemId)){
            stocks = itemStocks;
           break;
        }
    }
    itemFile.close();
    return stocks;
}
float item :: getPrice(int id){
    opener(itemFile,fileName,ios::in);
    if(!itemFile){
        // return -1;
        cout<<"Exit from getprice";
        exit(0);
    }
    cin.ignore();
    float price = 0.00;
    while (!itemFile.eof())
    {
        unpack();
        //cout<<"id "<<id<<"item id"<<itemId<<endl;
        if((id==itemId)){
            
           price =  pricePerUnit;
           break;
        }
    }
    itemFile.close();
    return price;
}
char * item::getItemName(int id){
    opener(itemFile,fileName,ios::in);
    if(!itemFile){
        cout<<"Exit from getItemName\n";
        exit(0);
    }
    while (1)
    {
        unpack();
        if(id==itemId)
        {
            itemFile.close();
            return itemName;
        }
    }
}