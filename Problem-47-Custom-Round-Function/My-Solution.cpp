#include <iostream>
#include <cmath>
using namespace std;
float GetFractionPart(float Number){return Number-int(Number);}
int MyRound(float Number){int IntPart=int(Number);float FractionPart=GetFractionPart(Number);if(abs(FractionPart)>=.5){if(Number>0)return ++IntPart;else return --IntPart;}return IntPart;}
float ReadNumber(){float Number;cout<<" please enter a number? ";cin>>Number;return Number;}
int main(){float Number=ReadNumber();cout<<"My Round Result : "<<MyRound(Number)<<endl;cout<<"My Round Result : "<<round(Number)<<endl;return 0;}
