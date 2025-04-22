//优先队列
#include <iostream>
#include <queue>

using namespace std;

long long n, temp, a, b, c;
priority_queue<long long> q;

int main()
{
    cin >> n;
    for(long long i = 1; i <= n; i++)
    {
        cin >> temp;
        q.push(temp);
    }
    a = q.top();
    q.pop();
    b = q.top();
    q.pop();
    c = q.top();
    q.pop();
    if(a + b + c >= n / 2) cout << "YES";
    else cout << "NO";
    
    return 0;
}