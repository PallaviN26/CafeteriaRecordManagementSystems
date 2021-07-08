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
    cout<<"1.Customer Service\t2.Order History\t3.Update Food List\t4.Orders To Prepare\n";
    cin>>choice;
    switch (choice)
    {
    case 1:
      item itemobj;
      itemobj.itemAccessing();
      /* code */
      break;
    case 2:
    case 3:
    case 4:
      cout<<"Not yet done\n";
      break;
    default:
      exit(0);
    }
  } 
  return 0;
}