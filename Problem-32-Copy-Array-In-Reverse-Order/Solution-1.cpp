#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void FillArrayWithRandomNumbers(int arr[100],int &arrlength){cout<<"Enter number of elements:";cin>>arrlength;for(int i=0;i<arrlength;i++)arr[i]=RandomNumbers(1,100);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";cout<<endl;}
void CopyArrayInReverseOrder(int arr[100],int arrDestination[100],int arrlength){for(int i=0;i<arrlength;i++)arrDestination[i]=arr[arrlength-1-i];}
int main(){srand((unsigned)time(NULL));int arr[100],arr2[100],arrlength;FillArrayWithRandomNumbers(arr,arrlength);CopyArrayInReverseOrder(arr,arr2,arrlength);cout<<"\nArray 1 elements : ";PrintArray(arr,arrlength);cout<<"\nArray elements after copy:\n";PrintArray(arr2,arrlength);}
