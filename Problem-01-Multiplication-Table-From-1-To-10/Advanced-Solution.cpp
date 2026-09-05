#include <iostream>
using namespace std;
void PrintTableHeader(int From , int To)
{
    cout<<"\n\t\t\t Multiplication Table  \n\n";
    for(int i = From ; i <=To ; i++)
    {
        cout<<"\t"<<i;

    }
    cout<<"\n";

    for(int i = From ; i<=To;i++)
    {
        cout<<"_________";
    }
    cout<<endl;
}
string ColumnSperator(int i,int To)
{
// if (i < 10)  دي عشان ميكونش في لغبطة في ال |
    if(i < To)
    return "    |";
    else
    return "   |";

}
void PrintMultiplicationTable(int From,int To)
{
    PrintTableHeader(From, To);
    for(int i = From ; i <= To ; i++)
    {
       cout<<" "<<i<<ColumnSperator(i,To)<<"\t";
       for(int j = From ; j <= To ; j++)
       {
           cout<<i*j<<"\t";
       }
       cout<<endl;
    }
    
}
int main()
{
    int From ,To;
    cout<<"Enter Start Number: ";
    cin>>From;

    cout<<"Enter end Number: ";
    cin>>To;

  PrintMultiplicationTable(From,To);
    return 0 ;
}
