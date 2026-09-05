#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void FillArrayWithRandomNumbers(int arr[100],int &arrlength){cout<<"Enter number of element : ";cin>>arrlength;for(int i=0;i<arrlength;i++)arr[i]=RandomNumbers(1,100);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";cout<<endl;}
int main(){srand((unsigned)time(NULL));int arr[100],arrlength;FillArrayWithRandomNumbers(arr,arrlength);cout<<"\nArray Elements : ";PrintArray(arr,arrlength);}
