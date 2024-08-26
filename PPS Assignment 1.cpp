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
  carobj1.brand="BMW";
  carobj1.model=" BMW M5 ";
  carobj1.year= 1998;
  
  //creating another object of car 
  Car carobj2;
  carobj2.brand="Lamborghini";
  carobj2.model="Huracan";
  carobj2.year= 2013;
  
  cout<<carobj1.brand<<carobj1.model<<carobj1.year<<endl;
  cout<<carobj2.brand<<carobj2.model<<carobj2.year<<endl;
  
  return 0;
}
