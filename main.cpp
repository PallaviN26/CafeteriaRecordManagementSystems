#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "Item.hpp"

#define MAX_BUFFER 75
using namespace std;

fstream myFile;
int main()
{
  int choice;
  while(1){
    cout<<"1.Customer Service\t2.Order History\t3.Update Food List\t4.Orders To Prepare\t5.Exit\n";
    cin>>choice;
    item itemobj;
    switch(choice)
    {
    case 1:{
           itemobj.accessing();
          
    }  break;
    case 2:{cout<<"Hello";
           
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