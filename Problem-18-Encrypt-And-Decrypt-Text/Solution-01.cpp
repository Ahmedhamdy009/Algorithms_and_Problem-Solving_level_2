#include <string>
#include <iostream>
using namespace std;
string ReadText()
{
    string Text;
    cout<<"Please enter your text : ";
    getline(cin,Text);
    return Text;
}
string EncryptText(string Text, short EncryptionKey)
{
    for(int i = 0; i < (int)Text.length(); i++)
    {
        Text[i] = char((int) Text[i] + EncryptionKey);
    }
    return Text;
}
string DecryptText(string Text, short EncryptionKey)
{
    for(int i = 0; i < (int)Text.length(); i++)
    {
        Text[i] = char((int) Text[i] - EncryptionKey);
    }
    return Text;
}
int main()
{
    const short EncryptionKey = 2;
    string TextBeforeEncryption = ReadText();
    string TextAfterEncryption = EncryptText(TextBeforeEncryption,EncryptionKey);
    string TextAfterDecryption = DecryptText(TextAfterEncryption,EncryptionKey);
    cout<<"Text Before Encryption : "<<TextBeforeEncryption<<endl;
    cout<<"Text After Encryption : "<<TextAfterEncryption<<endl;
    cout<<"Text After Decryption : "<<TextAfterDecryption<<endl;
}
