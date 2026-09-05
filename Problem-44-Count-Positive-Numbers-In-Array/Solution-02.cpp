#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void FillArrayWithRandomNumbers(int arr[100],int &arrLength){cout<<"Enter number of elements: ";cin>>arrLength;for(int i=0;i<arrLength;i++)arr[i]=RandomNumbers(-100,100);}
void PrintArray(int arr[100],int arrLength){for(int i=0;i<arrLength;i++)cout<<arr[i]<<" ";cout<<endl;}
void PrintPositiveNumbers(int arr[100],int arrLength){for(int i=0;i<arrLength;i++)if(arr[i]>0)cout<<arr[i]<<" ";cout<<endl;}
void PrintNegativeNumbers(int arr[100],int arrLength){for(int i=0;i<arrLength;i++)if(arr[i]<0)cout<<arr[i]<<" ";cout<<endl;}
int PositiveCount(int arr[100],int arrLength){int Counter=0;for(int i=0;i<arrLength;i++)if(arr[i]>0)Counter++;return Counter;}
int NegativeCount(int arr[100],int arrLength){int Counter=0;for(int i=0;i<arrLength;i++)if(arr[i]<0)Counter++;return Counter;}
int main(){srand((unsigned)time(NULL));int arr[100],arrLength=0;FillArrayWithRandomNumbers(arr,arrLength);cout<<"\nArray Elements:\n";PrintArray(arr,arrLength);cout<<"\nPositive Numbers:\n";PrintPositiveNumbers(arr,arrLength);cout<<"Positive Numbers Count: "<<PositiveCount(arr,arrLength)<<endl;cout<<"\nNegative Numbers:\n";PrintNegativeNumbers(arr,arrLength);cout<<"Negative Numbers Count: "<<NegativeCount(arr,arrLength)<<endl;return 0;}
