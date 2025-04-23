//字典序
//https://ac.nowcoder.com/acm/contest/107458/A
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char str[4] = {'A', 'B', 'C', 'D'}; 
    do
    {
        for(int i = 0; i < n; i++)
        {
            if(i) cout << "+";
            cout << str[i];
        }
        cout << " Problem" << endl;
    }while(next_permutation(str, str + n));
    
    
    return 0;
}