#include <iostream>
using namespace std;
int main() 
{
 cout<<"\n\t\t\t Multiplication Table From 1 To 10  \n\n";
 for(int i=1;i<=10;i++)
{
   if(i < 10)
   cout<<"\t"<<i;
   else
   cout<<"\t"<<i;
}
cout<<"\n";
 for(int i=0;i<=10;i++)
 {
   cout<<"________";
 }
cout<<"\n";
for(int i=1;i<=10;i++)
{
   if(i<10)
   cout<<i<<"    |";
   else
   cout<<i<<"   |";
   for(int j=1;j<=10;j++)
   {
      cout<<"\t"<<i*j;
   }
   cout<<endl;
}
}
