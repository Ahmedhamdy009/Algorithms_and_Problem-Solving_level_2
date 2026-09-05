#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void FillArrayWithRandomNumbers(int arr[100],int &arrlength){cout<<"Enter number of element : ";cin>>arrlength;for(int i=0;i<arrlength;i++)arr[i]=RandomNumbers(1,100);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";cout<<endl;}
void CopyArray(int arr[100],int arrDestination[100],int arrlength){for(int i=0;i<arrlength;i++)arrDestination[i]=arr[i];}
int main(){srand((unsigned)time(NULL));int arr[100],arrlength,arr2[100];FillArrayWithRandomNumbers(arr,arrlength);CopyArray(arr,arr2,arrlength);cout<<"\nArray 1 Element : ";PrintArray(arr,arrlength);cout<<"\nArray 2 Element after copy : ";PrintArray(arr2,arrlength);}
