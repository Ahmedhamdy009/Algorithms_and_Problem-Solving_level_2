#include <iostream>
#include <cmath>
using namespace std;
int MyFloor(float Number){if(Number>0)return int(Number);return int(Number)-1;}
float ReadNumber(){float Number;cout<<" please enter a number? ";cin>>Number;return Number;}
int main(){float Number=ReadNumber();cout<<"My MyFloor Result : "<<MyFloor(Number)<<endl;cout<<"My floor Result : "<<floor(Number)<<endl;return 0;}
