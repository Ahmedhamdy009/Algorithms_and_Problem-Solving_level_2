#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enPrimeOrNotPrime{Prime=1,NotPrime=2};
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void FillArrayWithRandomNumbers(int arr[100],int &arrlength){cout<<"Enter number of element : ";cin>>arrlength;for(int i=0;i<arrlength;i++)arr[i]=RandomNumbers(1,100);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";cout<<endl;}
enPrimeOrNotPrime checkPrime(int Number){int M=round(Number/2.0);for(int Counter=2;Counter<=M;Counter++)if(Number%Counter==0)return NotPrime;return Prime;}
void CopyOnlyPrimaryNumbers(int arr[100],int arrDestination[100],int arrlength,int& arr2length){int Counter=0;for(int i=0;i<arrlength;i++)if(checkPrime(arr[i])==Prime)arrDestination[Counter++]=arr[i];arr2length=Counter;}
int main(){srand((unsigned)time(NULL));int arr[100],arrlength,arr2[100],arr2length;FillArrayWithRandomNumbers(arr,arrlength);CopyOnlyPrimaryNumbers(arr,arr2,arrlength,arr2length);cout<<"\nArray 1 Element : ";PrintArray(arr,arrlength);cout<<"\nArray 2 Element after copy : ";PrintArray(arr2,arr2length);}
