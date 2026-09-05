#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
int ReadPositiveNumber(string Message){int Number=0;do{cout<<Message<<endl;cin>>Number;}while(Number<=0);return Number;}
void FillArrayWithRandomNumbers(int arr[100],int &arrlength){for(int i=0;i<arrlength;i++)arr[i]=RandomNumbers(1,100);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";cout<<endl;}
void SumOf2Arrays(int arr[100],int arr2[100],int arrSum[100],int arrlength){for(int i=0;i<arrlength;i++)arrSum[i]=arr[i]+arr2[i];}
int main(){srand((unsigned)time(NULL));int arr[100],arr2[100],arrSum[100];int arrlength=ReadPositiveNumber("How many elements ?");FillArrayWithRandomNumbers(arr,arrlength);FillArrayWithRandomNumbers(arr2,arrlength);SumOf2Arrays(arr,arr2,arrSum,arrlength);cout<<"\nArray 1 Elements : ";PrintArray(arr,arrlength);cout<<"\nArray 2 Elements : ";PrintArray(arr2,arrlength);cout<<"\nSum of array1 and array2 elements:\n";PrintArray(arrSum,arrlength);}
