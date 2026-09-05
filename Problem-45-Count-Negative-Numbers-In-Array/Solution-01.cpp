#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void FillArrayWithRandomNumbers(int arr[100],int &arrlength){cout<<"Enter number of elements : ";cin>>arrlength;for(int i=0;i<arrlength;i++)arr[i]=RandomNumbers(-100,100);}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";}
int NegativeCount(int arr[100],int arrLength){int Counter=0;for(int i=0;i<arrLength;i++)if(arr[i]<0)Counter++;return Counter;}
int main(){srand((unsigned)time(NULL));int arr[100],arrLength=0;FillArrayWithRandomNumbers(arr,arrLength);cout<<"\nArray Elements : \n";PrintArray(arr,arrLength);cout<<"\nNegative Numbers count is: "<<NegativeCount(arr,arrLength)<<endl;return 0;}
