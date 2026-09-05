#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int ReadPositiveNumber(string Message){int Number=0;do{cout<<Message<<endl;cin>>Number;}while(Number<=0);return Number;}
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void Swap(int& A,int& B){int Temp=A;A=B;B=Temp;}
void FillArrayWith1ToN(int arr[100],int &arrlength){for(int i=0;i<arrlength;i++)arr[i]=i+1;}
void ShuffleArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)Swap(arr[RandomNumbers(1,arrlength)-1],arr[RandomNumbers(1,arrlength)-1]);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";cout<<endl;}
int main(){srand((unsigned)time(NULL));int arr[100];int arrlength=ReadPositiveNumber("How many elements ?");FillArrayWith1ToN(arr,arrlength);cout<<"\nArray elements before shuffle: ";PrintArray(arr,arrlength);ShuffleArray(arr,arrlength);cout<<"\nArray elements after shuffle:\n";PrintArray(arr,arrlength);}
