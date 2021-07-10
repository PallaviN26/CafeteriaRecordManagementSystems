#include<iostream>
#include<cstring>
#include<fstream>
#include "Chefs.hpp"

#define fileName "chef.txt"
using namespace std;
fstream chefFile;

void chefs::opener(fstream &ifile,char *filename,ios_base::openmode mode){
    ifile.open(filename,mode);
    if(!ifile){
        cout<<"File not found\n";
        return;
    }
}
void chefs:: pack(){
    chefFile<<itemId<<"|"<<itemName<<"|"<<quantity<<"|#\n";
}

void chefs:: unpack(){
    char buffer[75],idBuf[10],quantityBuf[10];
    chefFile.getline(idBuf,10,'|');
    chefFile.getline(itemName,25,'|');
    chefFile.getline(quantityBuf,10,'|');
    chefFile.getline(buffer,75,'#\n');
    itemId=atoi(idBuf);
    quantity=atoi(quantityBuf);
}