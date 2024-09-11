#include <iostream>
#include <vector>
using namespace std;
bool valid(string mac)
{
    if (mac.length() == 17)
    {
        for (int i = 2; i < mac.length(); i = i + 3)
        {
            if ((int)mac[i] != 58)
                return false; // checking
        }
        for (int i = 0; i < mac.length(); i++)
        {
            int val = (int)mac[i];
            if (97 <= val && val <= 102)
                continue; // 97-102
            else if (65 <= val && val <= 70)
                continue; // 65-70
            else if (48 <= val && val <= 57)
                continue; // 0-9
            else if (val == 58)
                continue; // 0-9
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}
vector<int> binary(int n)
{
    vector<int> ans;
    while (n)
    {
        int digit = n % 2;
        ans.push_back(digit);
        n /= 2;
    }
    while (ans.size() < 4)
    {
        ans.push_back(0);
    }
    int i = 0, j = ans.size() - 1;
    while (i < j)
    {
        // cout<<"here";
        int temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
        i++, j--;
    }
    return ans;
}
int getvalue(char n)
{
    int val = (int)n;
    // cout<<val<<endl;
    if (97 <= val && val <= 102)
    { // a to f
        n = n - 'a' + 10;
    }
    else if (65 <= val && val <= 70)
    { // A to F
        n = n - 'A' + 10;
    }
    else if (48 <= val && val <= 57)
    { // 0-9
        n = n - '0';
    }
    return n;
}
void printBinary(string mac){
    vector<char>allbinary;
    //trying to get all binary representation;
    for(int j=0;j<mac.length();j=j+3){
            int first = getvalue(mac[j]);
            int second = getvalue(mac[j+1]);
            vector<int> firstBinary = binary(first);
            vector<int> secondBinary = binary(second);
            vector<int> combineFirstBinary;
            for (int i = 0; i < firstBinary.size(); i++)
            {
                allbinary.push_back(firstBinary[i]+48);
            }
            for (int i = 0; i < secondBinary.size(); i++)
            {
                allbinary.push_back(secondBinary[i]+48);
            }
            if(j==mac.size()-2)
            {
                continue;
            }
            allbinary.push_back(':');
    }
    for(int i=0;i<allbinary.size();i++){
        cout<<allbinary[i];
    }
    cout<<endl;
}

int main()
{
    // a-97 f-102
    // A-65 F-70
    // 0-48 9-57
    //:-58
    cout<<"Hexdecimal Values Only -----------(0-9)(a-f)(A-F)       " << endl;
    cout<<"Address should in this Format ---XX:XX:XX:XX:XX:XX      "<< endl;
    cout<<endl;
    // input taken
    string mac;
    do
    {
        cout << "Enter Address : ";
        cin >> mac;
    } while (valid(mac) == 0);
    int first = getvalue(mac[0]);   
    int second = getvalue(mac[1]);
    vector<int> firstBinary = binary(first);
    vector<int> secondBinary = binary(second);
    vector<int> combineFirstBinary;
    for (int i = 0; i < firstBinary.size(); i++)
    {
        combineFirstBinary.push_back(firstBinary[i]);
    }
    for (int i = 0; i < secondBinary.size(); i++)
    {
        combineFirstBinary.push_back(secondBinary[i]);
    }
    int lastbit = combineFirstBinary[combineFirstBinary.size() - 1];
    //binary representation
    cout<<endl;
    cout<<"Address(HexDec): "<<mac<<endl;
    cout<<"Address(Binary): ";
    printBinary(mac);
    if (mac == "ff:ff:ff:ff:ff:ff"||mac=="FF:FF:FF:FF:FF:FF")
    {
        cout << "Address Type   : Boardcast Type" << endl;
    }
    else if (lastbit == 0)
    {
        cout << "Address Type   : Unicast Type";
    }
    else if (lastbit == 1)
    {
        cout << "Address Type   : Multicast Type";
    }
}
// 4a:30:10:21:10:1a even uni
// 47:20:1b:2e:08:ee  odd multi
// ff:ff:ff:ff:ff:ff  board
