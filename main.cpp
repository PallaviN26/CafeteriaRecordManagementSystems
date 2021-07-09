#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Item.hpp"
#include "OrderDetails.hpp"

#define MAX_BUFFER 75
using namespace std;

fstream myFile;
int main()
{
  int choice;
  while(1){
    cout<<"1.Customer Service\t2.Order History\t3.Modification Of Menu\t4.Service In Progress\t5.Exit\nEnter choice: ";
    cin>>choice;
    item itemobj;
    switch(choice)//first switch(main switch)
    {
    case 1:{
           itemobj.accessing();
          
    }  break;
    case 2:{
            
            }  break;
    case 3:cout<<"Byee";
            break;
    case 4:cout<<"Tata";
           break;
    default:  return 0;
    }
    myFile.close();
  } 
  return 0;
}
