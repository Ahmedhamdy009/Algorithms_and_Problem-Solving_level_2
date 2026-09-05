#include <iostream>
using namespace std;
int ReadNumber(){int Number;cout<<"Please enter a number?\n";cin>>Number;return Number;}
void AddArrayElement(int arr[100],int Number,int &arrlength){arrlength++;arr[arrlength-1]=Number;}
bool ReadAddMore(){int Choice;do{cout<<"Do you want to add more numbers? [0]: No, [1]: Yes? ";cin>>Choice;if(Choice!=0&&Choice!=1)cout<<"Invalid choice! Please enter only 0 or 1.\n";}while(Choice!=0&&Choice!=1);return Choice==1;}
void InputUserNumbersInArray(int arr[100],int &arrlength){bool AddMore=true;do{AddArrayElement(arr,ReadNumber(),arrlength);AddMore=ReadAddMore();}while(AddMore);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";cout<<endl;}
int main(){int arr[100],arrlength=0;InputUserNumbersInArray(arr,arrlength);cout<<"\nArray Length: "<<arrlength<<endl;cout<<"Array Elements: ";PrintArray(arr,arrlength);return 0;}
