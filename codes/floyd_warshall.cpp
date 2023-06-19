#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
const ll MOD = 1e9+7; // 998244353;
#define INF 10000000000000

ll min(ll a, ll b)
{
    return a<b?a:b;
}

void floyd_warshall(ll n, ll** adj)
{
    ll adj_next[n][n];
    for(int k=0;k<n;k++)
    {
        for(int x=0;x<n;x++)
        {
            for(int y=0;y<n;y++)
            {
                adj_next[x][y] = min(adj[x][y],adj[x][k]+adj[k][y]);
            }
        }
        for(int x=0;x<n;x++)
            for(int y=0;y<n;y++)
                adj[x][y]=adj_next[x][y];
    }
}


int main()
{
    ll** adj;
    ll n,m;
    cin>>n>>m;
    adj = new ll*[n];
    for(int x=0;x<n;x++)
    {
        adj[x]=new ll[n];
    }
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            if(x!=y)
                adj[x][y]=INF;
            else
                adj[x][y]=0;
        }
    }
    for(int x=0;x<m;x++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u][v]=w;
    }

    floyd_warshall(n,adj);
    
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<n;y++)
        {
            cout<<adj[x][y]<<" ";
        }
        cout<<endl;
    }


    return 0;
}

/*
input : 
4 7
2 1 8
1 2 3
4 1 2
1 4 7
3 4 1
3 1 5
2 3 2

output : 
0 3 5 6 
5 0 2 3 
3 6 0 1 
2 5 7 0 
*/