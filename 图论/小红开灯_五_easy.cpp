#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define MAXN 500010
#define ios ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
int e[MAXN],ne[MAXN],h[MAXN],idx;
bool st[MAXN];
void add(int a,int b){
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}
int res;
void dfs(int u,int f){
    int ans=0;
    for(int i=h[u];i!=-1;i=ne[i]){
        if(e[i]==f)continue;
        dfs(e[i],u);
        if(!st[e[i]])ans++;
    }
    if(!st[u]&&ans){
        st[u]=true;
        st[f]=true;
        res++;
    }
}
signed main(){
	memset(h,-1,sizeof h);
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        add(a,b);
        add(b,a);
    }
    dfs(1,0);
    cout<<res;
	return 0;
} 