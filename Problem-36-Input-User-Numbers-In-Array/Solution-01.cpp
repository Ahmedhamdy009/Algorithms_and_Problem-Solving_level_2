#include <iostream>
using namespace std;
int ReadNumber(){int Number;cout<<"Please enter a number ?\n ";cin>>Number;return Number;}
void AddArrayElement(int arr[100],int Number,int &arrlength){arrlength++;arr[arrlength-1]=Number;}
void InputUserNumbersInArray(int arr[100],int &arrlength){bool AddMore=true;do{AddArrayElement(arr,ReadNumber(),arrlength);cout<<"Do you want to add more numbers ? [0]:No , [1]:yes? ";cin>>AddMore;}while(AddMore);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";}
int main(){int arr[100],arrlength=0;InputUserNumbersInArray(arr,arrlength);cout<<"Array Length: "<<arrlength<<endl;cout<<"Array elements : ";PrintArray(arr,arrlength);return 0;}
