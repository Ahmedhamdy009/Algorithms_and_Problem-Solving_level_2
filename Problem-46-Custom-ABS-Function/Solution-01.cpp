#include <iostream>
#include <cstdlib>
using namespace std;
float MyABS(float Number){if(Number>0)return Number;return Number*-1;}
float ReadNumber(){float Number;cout<<" please enter a number? ";cin>>Number;return Number;}
int main(){float Number=ReadNumber();cout<<"My abs Result : "<<MyABS(Number)<<endl;cout<<"My C++ Result : "<<abs(Number)<<endl;return 0;}
