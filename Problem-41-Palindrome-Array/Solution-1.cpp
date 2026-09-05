#include <iostream>
using namespace std;
void FillArray(int arr[100],int &arrlength){arrlength=6;int values[6]={10,20,30,30,20,10};for(int i=0;i<6;i++)arr[i]=values[i];}
void PrintArray(int arr[100],int arrlength){for(int i=0;i<arrlength;i++)cout<<arr[i]<<" ";}
bool IsPalindromeArray(int arr[100],int length){for(int i=0;i<length;i++)if(arr[i]!=arr[length-i-1])return false;return true;}
int main(){int arr[100],length=0;FillArray(arr,length);cout<<"\nArray Elements : \n";PrintArray(arr,length);if(IsPalindromeArray(arr,length))cout<<"\nYes array is Palindrome ";else cout<<"\nNo array is Not Palindrome ";return 0;}
