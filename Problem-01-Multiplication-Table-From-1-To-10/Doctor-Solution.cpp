#include <iostream>
using namespace std;
void PrintTableHeader()
{
   cout<<"\n\t\t\t Multiplication Table From 1 To 10  \n";
   for(int i=1;i<=10;i++)
   {
     cout<<"\t"<<i;
   }
   cout<<"\n__________________________________________________________________________________\n";
}
string ColumnSperator(int i)
{
   if(i < 10)
   return "   |";
   else
   return "  |";

}
void PrintMultiplicationTable() 
{
   PrintTableHeader();
   for(int i=1;i<=10;i++)
   {
      cout<<" "<<i<<ColumnSperator(i)<<"\t";
      for(int j=1;j<=10;j++)
      {
         cout<<i*j<<"\t";
      }
      cout<<endl;
   }
}
int main() 
{
 PrintMultiplicationTable();
}
