#include <iostream>
using namespace std;
void FillArray(int arr[100],int &arrLength){arrLength=10;int values[10]={10,10,10,50,50,70,70,70,70,90};for(int i=0;i<10;i++)arr[i]=values[i];}
void PrintArray(int arr[100],int arrLength){for(int i=0;i<arrLength;i++)cout<<arr[i]<<" ";cout<<"\n";}
short FindNumberPositionInArray(int Number,int arr[100],int arrLength){for(int i=0;i<arrLength;i++)if(arr[i]==Number)return i;return -1;}
bool IsNumberInArray(int Number,int arr[100],int arrLength){return FindNumberPositionInArray(Number,arr,arrLength)!=-1;}
void AddArrayElement(int Number,int arr[100],int &arrLength){arrLength++;arr[arrLength-1]=Number;}
void CopyDistinctNumbersToArray(int arrSource[100],int arrDestination[100],int SourceLength,int &DestinationLength){for(int i=0;i<SourceLength;i++)if(!IsNumberInArray(arrSource[i],arrDestination,DestinationLength))AddArrayElement(arrSource[i],arrDestination,DestinationLength);}
int main(){int arrSource[100],SourceLength=0,arrDestination[100],DestinationLength=0;FillArray(arrSource,SourceLength);CopyDistinctNumbersToArray(arrSource,arrDestination,SourceLength,DestinationLength);cout<<"\nArray 1 elements:\n";PrintArray(arrSource,SourceLength);cout<<"\nArray 2 distinct elements:\n";PrintArray(arrDestination,DestinationLength);return 0;}
