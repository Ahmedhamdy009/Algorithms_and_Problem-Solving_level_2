#include <iostream>
using namespace std;
void FillArray(int arr[100],int &length){cout<<"Enter number of elements: ";cin>>length;for(int i=0;i<length;i++){cout<<"Enter element ["<<i+1<<"]: ";cin>>arr[i];}}
void PrintArray(int arr[100],int length){for(int i=0;i<length;i++)cout<<arr[i]<<" ";}
bool IsPalindromeArray(int arr[100],int length){for(int i=0;i<length;i++)if(arr[i]!=arr[length-i-1])return false;return true;}
int main(){int arr[100],length=0;FillArray(arr,length);cout<<"\nArray Elements:\n";PrintArray(arr,length);if(IsPalindromeArray(arr,length))cout<<"\nYes, array is Palindrome.";else cout<<"\nNo, array is not Palindrome.";return 0;}
