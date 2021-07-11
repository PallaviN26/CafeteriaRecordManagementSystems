#include<iostream>
#include <stdlib.h>
#include <iomanip>
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

void chefs :: display(){
    opener(chefFile,fileName,ios::in);
    if(!chefFile){
        return;
    }
    cout<<setiosflags(ios::left);
    cout<<setw(10)<<"Item Id"<<setw(25)<<"Item Name"<<setw(10)<<"Quantity"<<endl;
    while(!chefFile.eof()){
        unpack();
        cout<<setw(10)<<itemId<<setw(25)<<itemName<<setw(10)<<quantity<<endl;
    }
    chefFile.close();
}

void chefs :: modify(){
    int id , num ;
    cout<<"Enter item id";
    cin >> id;
    cout<<"Enter quantity of item prepared";
    cin >> num;
    int pos;
    opener(chefFile,fileName,ios::in|ios::binary|ios::out);
    while(!chefFile.eof()){
        pos = chefFile.tellg();
        unpack();
        if(chefFile){
            if(itemId == id){
                chefFile.seekp(pos);
                quantity -= num;
                pack();
                break;
            }
        }
    }
    chefFile.close();
}
void  chefs::accessing(){
    int choice;
    cout<<"1. View orders to prepare \t2. Update prepared order \n"
    cout<< "Enter your choice \n";
    cin >> choice;
    switch (choice)
    {
    case : display();
        break;
    
    default: modify();
        break;
    }
}