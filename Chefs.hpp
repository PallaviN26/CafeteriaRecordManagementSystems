#include<string>
#include<fstream>
#ifndef CHEFS_HPP
#define CHEFS_HPP
using namespace std;
class chefs {
   public :
   int  itemId;
   char itemName[25];
   int quantity;
   public:
        void opener(fstream &ifile,char *fileName,ios_base::openmode mode);
       void read(int id,char * name,int q) ;
       void pack() ;
       void unpack() ;
       void display() ;
       void search() ;
       void removeRecord() ;
       void modify();
       void accessing();
};
#endif