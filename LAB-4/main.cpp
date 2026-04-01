#include <iostream>

using namespace std;

struct Package{
    string packageID;
    string destinationCity;
    int dimension[3];
    Package* next=NULL;
};

Package* stackTop=ptr;
const int QUEUE_SIZE = 5;

struct Courier{
    string courierName;
    string vehicleType;
};

void Arrival(string id, string city, int l,int w, int h){
    Package* newPackage= new Package;
    newPackage->packageID= id;
    newPackage->destinationCity=city;
    newPackage->deminesion[0]=l;
    newPackage->deminesion[1]=w;
    newPackage->deminesion[2]=h;

    newPackage->next = stackTop;
    stackTop= newPackage;
};

void CourierRegister(){
    if((rear+1)% QUEUE_SIZE == front){
        cout << "ERROR" << endl;
        reurn;
    }
    if (front == -1) front =0;
    rear= (rear+1)% QUEUE_SIZE;

};

void Dispatch(){
    if(stackTop == ptr){
        cout << "Hata" << endl;
        return;
    }

};

void Display(){

};

int main()
{

    return 0;
}
