#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void FillArrayWithRandomNumbers(int arr[100],int &arrlength){cout<<"Enter number of elements : ";cin>>arrlength;for(int i=0;i<arrlength;i++)arr[i]=RandomNumbers(1,100);}
void AddArrayElement(int arr[100],int Number,int &arrlength){arrlength++;arr[arrlength-1]=Number;}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";}
void CopyArrayUsingAddArrayElement(int arr[100],int arrDestination[100],int arrlength,int &arrDestinationLength){for(int i=0;i<arrlength;i++)AddArrayElement(arrDestination,arr[i],arrDestinationLength);}
int main(){srand((unsigned)time(NULL));int arr[100],arr2[100],arrlength=0,arr2length=0;FillArrayWithRandomNumbers(arr,arrlength);CopyArrayUsingAddArrayElement(arr,arr2,arrlength,arr2length);cout<<"\nArray 1 elements : \n";PrintArray(arr,arrlength);cout<<"\nArray 2 elements after copy: \n";PrintArray(arr2,arr2length);return 0;}
