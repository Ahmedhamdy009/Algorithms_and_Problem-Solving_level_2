#include <string>
#include <iostream>
using namespace std;
int ReadPositiveNumber(string Message){int Number=0;do{cout<<Message;cin>>Number;}while(Number<0);return Number;}
void ReadArray(int arr[100],int &arrlength){cout<<"Enter number of element : ";cin>>arrlength;for(int i=0;i<arrlength;i++){cout<<"Elements ["<<i+1<<"] : ";cin>>arr[i];}}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";cout<<endl;}
int TimeRepeated(int arr[100],int arrlength,int Number){int counter=0;for(int i=0;i<arrlength;i++)if(arr[i]==Number)counter++;return counter;}
int main(){int arr[100],arrlength,NumberOfCheck;ReadArray(arr,arrlength);NumberOfCheck=ReadPositiveNumber("Enter the number you want to check : ");cout<<"Original Array : ";PrintArray(arr,arrlength);cout<<" Number "<<NumberOfCheck<<" is repeated "<<TimeRepeated(arr,arrlength,NumberOfCheck)<<" time(s)"<<endl;}
