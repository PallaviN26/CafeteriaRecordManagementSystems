#include <stdio.h>
#include<limits>
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <typeinfo>
#include <math.h>
#include "Item.hpp"
#include "OrderDetails.hpp"
#include "Bill.hpp"
#define fileName "item.txt"
using namespace std;
fstream itemFile;

void item ::opener(fstream &ifile, char *filename, ios_base::openmode mode)
{
    ifile.open(filename, mode);
    if (!ifile)
    {
        cout << "File not found\n";
        return;
    }
}

int item :: hash (int id){
    int tableSize = 6; //  number of buckets
    float constant = 0.789213;
    return floor(tableSize * frac(id * constant));
}
float item :: frac(float x){
     return x - floor(x);
}
void item::read()
{
    opener(itemFile, fileName, ios::in|ios::out|ios::binary);
    if (!itemFile)
    {
        cout<<"Exit through item read\n";
        exit(0);
    }
    char temp;
    cout << "Enter details:\n";
    do
    {
        cout << "Enter item id: ";
        cin >> itemId;
        if(cin.good())
            break;
        cin.clear();
        string str;
        cin>>str;
        if(str=="quit")
        break;
        cout<<"\n Enter valid input for id(whole number)\n";
    } while(1);
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "Enter food item name: ";
    gets(itemName);
    cout << "Enter item category: ";
    gets(itemCategory);
    
    do
    {
        cout << "Enter item stock: ";
        cin >> itemStocks;
        if(cin.good())
            break;
        cin.clear();
        string str;
        cin>>str;
        if(str=="quit")
            break;
        cout<<"\n Enter valid input for stocks(whole number)\n";
    } while(1);
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    do
    {
        cout << "Enter price per unit: ";
        cin >> pricePerUnit;
        if(cin.good())
            break;
        cin.clear();
        string str;
        cin>>str;
        if(str=="quit")
            break;
        cout<<"\n Enter valid input for price per unit(float value)";
    } while(1);
     int addr = hash(itemId);
    cout<<"address: "<<addr<<endl;
    int bucketSize = 6;
    int noOfBuckets = 5;
    int pos = addr * (sizeof(item) + 6) * noOfBuckets;
    // for (int i = 0; i < 30; i++)
    // {
    //     itemFile.seekp(i * (sizeof(item) + 6), ios::beg);
    //     for (int j = 0; j < sizeof(item) + 5; j++)
    //         itemFile << "#";
    //     itemFile << endl;
    // }
    itemFile.seekg(pos, ios::beg);
    char ch = itemFile.peek();
    if (ch != '#')
    {
        cout<<ch;
        int i = 0;
        char dummy[10];
        while (ch != '#' && i < bucketSize)
        {
            itemFile.getline(dummy, 10, '|');
            int id = atoi(dummy);
            cout<<id;
            if (id != itemId)
            {
                cout<<"pos before:"<<pos<<endl;
                pos += sizeof(item) + 6;
                cout<<"pos after:"<<pos<<endl;
                i++;
                itemFile.seekp(pos, ios::beg);
                ch = itemFile.peek();
            }
            else
            {
                itemFile.seekg(pos, ios::beg);
                int quantity = itemStocks;
                unpack();
                itemStocks += quantity;
                itemFile.seekp(pos, ios::beg);
                pack();
                itemFile.close();
                return;
            }
        }
        if (i == bucketSize)
        {
            cout << " Bucket overflow";
            itemFile.close();
            return;
        } else {
            pack();
        }
    }
    else
        pack();
    itemFile.close();
}

void item::pack()
{
    itemFile << itemId << "|" << itemName << "|" << itemCategory << "|" << itemStocks << "|" << pricePerUnit << "|";
}
void item::display()
{
    opener(itemFile, fileName, ios::in);
    if (!itemFile)
    {

        return;
    }
    char buffer[100];
    cout << setiosflags(ios::left);
    cout << setw(10) << "Item Id" << setw(25) << "Item Name" << setw(25) << "Item Category" << setw(10) << "Stock" << setw(10) << "Price" << endl;
    while (1)
    {
        unpack();
        if (itemFile.eof())
            break;
        else if ((itemStocks) > 0)
        {
            cout << setw(10) << itemId << setw(25) << itemName << setw(25) << itemCategory << setw(10) << itemStocks << setw(10) << pricePerUnit << endl;
        }
        // i--;
    }
    itemFile.close();
}

void item::unpack()
{
    char buffer[100];
    char stackBuf[10], priceBuf[10], idBuf[10];
    itemFile.getline(idBuf, 10, '|');
    itemFile.getline(itemName, 25, '|');
    itemFile.getline(itemCategory, 25, '|');
    itemFile.getline(stackBuf, 10, '|');
    itemFile.getline(priceBuf, 10, '|');
    itemId = atoi(idBuf);
    itemStocks = atoi(stackBuf);
    pricePerUnit = atof(priceBuf);
    itemFile.getline(buffer, 100, '#\n');
}
int item::search(int id)
{
    //display();
    opener(itemFile, fileName, ios::in);
    if (!itemFile)
    {
        return -1;
    }
    cin.ignore();
    int count = 0;
    while (!itemFile.eof())
    {
        unpack();
        if ((id == itemId))
        {
            return count++;
        }
        count++;
    }
    cout << "Item not found!\n";
    return 0;
    itemFile.close();
}
void item :: modify(int id , int stocks){
   int pos ;
   opener(itemFile,fileName,ios::in | ios :: binary | ios :: out );
   while(!itemFile.eof()){
       pos = itemFile.tellg();
       //cout<<"Position in item modify: "<<pos<<endl;
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
  int orderIdRef;
  orderDetails od(0);
  Bill b;
  int modifyItemId,modifyQuantity;
  while (1)
  {
    menu:
    cout << "\n1-Menu\t2-Take order\t3-exit\nEnter choice:";
    cin >> mainchoice;
    switch (mainchoice) //second switch(menu switch)
    {
    case 1:
        display();
        break;
    takeOrder:
    case 2:
        if (od.flag == 0)
        {
            od.orderId = od.generateOrderId();
            orderIdRef = od.orderId;
            od.flag = 1;
        }
        od.read();
        while (1)
        {
                //orderProgress:
            cout << "\n1.View order\t2.Continue Ordering\t3.Return\nEnter choice: ";
            cin >> takeOrderChoice;
            switch (takeOrderChoice)
            {
            case 1:
                od.particularOrderAccessing(orderIdRef,0);
                while (1)
                {
                    cout << "\n1.Modify Order\t2.Generate Bill\t3.Continue Ordering\t4.Cancel Order\nEnter choice: ";
                    cin >> viewOrderChoice;
                    od.orderId = orderIdRef;
                    switch (viewOrderChoice)
                    {
                    case 1:
                        // cout<<"Modify order";
                        cout<<"Enter details to modify\nItem Id: ";
                        cin>>modifyItemId;
                        cout<<"\nItem qauntity : ";
                        cin>>modifyQuantity;
                        od.modify(orderIdRef,modifyItemId,modifyQuantity);
                        break;
                    case 2:
                        // cout<<"\nBil generate\n";
                        b.read(orderIdRef);
                        cout<<orderIdRef<<endl;//for bill 
                        od.particularOrderAccessing(orderIdRef,1);
                        // cout<<"Total Qauntity : "<<od.calculateTotalQuantity(orderIdRef);
                        cout<<"Total Amount : "<<od.calculateTotalAmount(orderIdRef)<<endl;
                        od.flag=0;
                        goto menu;
                        break;
                    case 3:
                        goto takeOrder;
                        break;
                    default:
                        
                        //od.deleteOrder(orderIdRef);
                        od.flag=0;
                        cout << "\nOrder cancelled so modify order file and to main menu\n";
                        goto menu; //goto takeOrder;
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
int item::getQuantity(int id)
{
    opener(itemFile, fileName, ios::in);
    int stocks = 0;
    if (!itemFile)
    {
        cout << "Exit from getquantity";
        // return -1;
        exit(0);
    }
    while (!itemFile.eof())
    {
        unpack();
        if ((id == itemId))
        {
            stocks = itemStocks;
            break;
        }
    }
    itemFile.close();
    return stocks;
}
float item ::getPrice(int id)
{
    opener(itemFile, fileName, ios::in);
    if (!itemFile)
    {
        // return -1;
        cout << "Exit from getprice";
        exit(0);
    }
    cin.ignore();
    float price = 0.00;
    while (!itemFile.eof())
    {
        unpack();
        //cout<<"id "<<id<<"item id"<<itemId<<endl;
        if ((id == itemId))
        {

            price = pricePerUnit;
            break;
        }
    }
    itemFile.close();
    return price;
}
char *item::getItemName(int id)
{
    opener(itemFile, fileName, ios::in);
    if (!itemFile)
    {
        cout << "Exit from getItemName\n";
        exit(0);
    }
    while (1)
    {
        unpack();
        if (id == itemId)
        {
            itemFile.close();
            return itemName;
        }
    }
}
void item ::operationsOnItem()
{
    int choice;
    while (1)
    {
        cout << "1. Add new item \t"
             << "2. Delete item \t "
             << "3. Update quantity \t"
             << "4. Update price\t"
             << "5. Main menu\n";
        cout<<"Enter your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            read();
        }
        break;
        case 2:
        {
            int id;
            cout << "Enter the item id :";
            cin >> id;
            int stocks = getQuantity(id);
            modify(id, stocks * -1);
        }
        break;
        case 3:
        {
            int id, stocks;
            cout << "Enter the item id :";
            cin >> id;
            cout << "Enter the quantity of item :";
            cin >> stocks;
            modify(id, stocks);
        }
        break;
        case 4:
        {
            int id;
            float price;
            cout << "Enter the item id ";
            cin >> id;
            cout << "Enter the updated price :";
            cin >> price;
            int pos;
            opener(itemFile, fileName, ios::in | ios ::binary | ios ::out);
            while (!itemFile.eof())
            {
                pos = itemFile.tellg();
                unpack();
                if (itemFile)
                {
                    if (id == itemId)
                    {
                        pricePerUnit = price;
                        itemFile.seekp(pos);
                        pack();
                        break;
                    }
                }
            }
            itemFile.close();
        }
        break;
        case 5 : return;
        }
    }
}