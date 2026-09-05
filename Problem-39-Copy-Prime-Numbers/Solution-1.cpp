#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;
enum enPrimeOrNotPrime{Prime=1,NotPrime=2};
enPrimeOrNotPrime checkPrime(int Number){if(Number<2)return NotPrime;int M=round(Number/2.0);for(int Counter=2;Counter<=M;Counter++)if(Number%Counter==0)return NotPrime;return Prime;}
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void FillArrayWithRandomNumbers(int arr[100],int &arrlength){cout<<"Enter number of elements : ";cin>>arrlength;for(int i=0;i<arrlength;i++)arr[i]=RandomNumbers(1,100);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";}
void AddArrayElement(int arr[100],int Number,int &arrlength){arrlength++;arr[arrlength-1]=Number;}
void CopyPrimeNumbers(int arr[100],int arrDestination[100],int arrlength,int &arrDestinationLength){for(int i=0;i<arrlength;i++)if(checkPrime(arr[i])==Prime)AddArrayElement(arrDestination,arr[i],arrDestinationLength);}
int main(){srand((unsigned)time(NULL));int arr[100],arr2[100],arrlength=0,arr2length=0;FillArrayWithRandomNumbers(arr,arrlength);CopyPrimeNumbers(arr,arr2,arrlength,arr2length);cout<<"\nArray 1 elements : \n";PrintArray(arr,arrlength);cout<<"\nArray 2 Prime numbers:: \n";PrintArray(arr2,arr2length);return 0;}
