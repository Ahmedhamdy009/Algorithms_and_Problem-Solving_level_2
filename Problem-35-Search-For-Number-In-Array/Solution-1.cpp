#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
int RandomNumbers(int From,int To){return From+rand()%(To-From+1);}
void FillArrayWithRandomNumbers(int arr[100],int &arrlength){cout<<"Enter number of elements : ";cin>>arrlength;for(int i=0;i<arrlength;i++)arr[i]=RandomNumbers(1,100);}
void PrintArray(int arr[100],int arrlength){cout<<"Array 1 Elements : \n";for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";}
short FindNumberPositionInArray(int arr[100],int Number,int arrlength){for(int i=0;i<arrlength;i++)if(arr[i]==Number)return i;return -1;}
int ReadNumber(){int Number;cout<<"\nPlease enter a number to search for?\n ";cin>>Number;return Number;}
bool IsNumberInArray(int arr[100],int Number,int arrlength){return FindNumberPositionInArray(arr,Number,arrlength)!=-1;}
int main(){srand((unsigned)time(NULL));int arr[100],arrlength;FillArrayWithRandomNumbers(arr,arrlength);PrintArray(arr,arrlength);int Number=ReadNumber();cout<<"Number you are looking for is: "<<Number<<endl;if(!IsNumberInArray(arr,Number,arrlength))cout<<"No, The number is not found :-(";else cout<<"Yes it is found :-)";return 0;}
