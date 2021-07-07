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
  item obj;
  obj.itemId = 123;
  cout<<obj.itemId;
  return 0;
}