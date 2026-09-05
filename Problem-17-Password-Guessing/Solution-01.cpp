#include <iostream>
using namespace std;
string ReadPassword(string Message)
{
    string Password;
    cout<<Message<<endl;
    cin>>Password;
    return Password;
}
bool GuessPassword(string Password)
{
    cout << "\n";
    string word = "";
    int Counter = 0;
    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                Counter++;
                word = word + char(i);
                word = word + char(j);
                word = word + char(k);
                cout<<"Trial ["<<Counter << "] : "<<word<<endl;
                if (Password == word)
                {
                    cout<<"\nPassword is : "<<word<<endl;
                    cout<<"Found after "<<Counter<<" Trial(s) \n";
                    return true;
                }
                word = "";
            }
        }
    }
    return false;
}
int main()
{
 GuessPassword(ReadPassword("Please Enter the Password"));
 return 0;
}
