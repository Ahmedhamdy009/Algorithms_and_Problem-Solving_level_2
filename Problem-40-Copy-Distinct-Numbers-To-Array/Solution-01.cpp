#include <iostream>
using namespace std;
void FillArray(int arr[100],int &arrlength){arrlength=10;int values[10]={10,10,10,50,50,70,70,70,70,90};for(int i=0;i<10;i++)arr[i]=values[i];}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";}
short FindNumberPositionInArray(int arr[100],int Number,int arrlength){for(int i=0;i<arrlength;i++)if(arr[i]==Number)return i;return -1;}
bool IsNumberInArray(int arr[100],int Number,int arrlength){return FindNumberPositionInArray(arr,Number,arrlength)!=-1;}
void AddArrayElement(int arr[100],int Number,int &arrlength){arrlength++;arr[arrlength-1]=Number;}
void CopyDistinctNumbersToArray(int arr[100],int arrDestination[100],int arrlength,int &arrDestinationLength){for(int i=0;i<arrlength;i++)if(!IsNumberInArray(arrDestination,arr[i],arrDestinationLength))AddArrayElement(arrDestination,arr[i],arrDestinationLength);}
int main(){int arr[100],arr2[100],arrlength=0,arr2length=0;FillArray(arr,arrlength);CopyDistinctNumbersToArray(arr,arr2,arrlength,arr2length);cout<<"\nArray 1 elements : \n";PrintArray(arr,arrlength);cout<<"\nArray 2 distinct numbers:: \n";PrintArray(arr2,arr2length);return 0;}
