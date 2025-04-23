#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string str, sss;
long len;
map<char, vector<long>> mp;

int main()
{
    getline(cin, str);
    len = str.length();
    for(long i = 0; i < len; i++)
    {
        mp[str[i]].push_back(i);
    }

    cin.ignore();
    getline(cin, sss);
    return 0;
}