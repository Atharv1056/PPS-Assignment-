#include<iostream>
using namespace std;

class Car
{
  public:
  string brand;
  string model;
  int year;
  
};

int main()
{
  Car carobj1;
  carobj1.brand="Dodge";
  carobj1.model=" Challenger SRT ";
  carobj1.year= 1982;
  
  //creating another object of car 
  Car carobj2;
  carobj2.brand="Nissan";
  carobj2.model=" Skyline GT-r";
  carobj2.year= 1972;
  
  cout<<carobj1.brand<<carobj1.model<<carobj1.year<<endl;
  cout<<carobj2.brand<<carobj2.model<<carobj2.year<<endl;
  
  return 0;
}