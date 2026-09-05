#include <iostream>
#include <cmath>
using namespace std;
float GetFractionPart(float Number){return Number-int(Number);}
int MyCeil(float Number){if(abs(GetFractionPart(Number))>0){if(Number>0)return int(Number)+1;return int(Number);}return Number;}
float ReadNumber(){float Number;cout<<" please enter a number? ";cin>>Number;return Number;}
int main(){float Number=ReadNumber();cout<<"My MyCeil Result : "<<MyCeil(Number)<<endl;cout<<"My ceil Result : "<<ceil(Number)<<endl;return 0;}
