#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
const ll MOD = 1e9+7; // 998244353;


// takes input an adjacency list of a graph and returns shortest distance of each node from 's'
vll bfs(vector<vll> adj, ll s)
{
    ll n = adj.size();

    queue<ll> q;
    bool visited[n]={0};
    vll d(n,-1);

    s--;
    q.push(s);
    visited[s]=1;
    d[s]=0;

    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        for(ll v : adj[u])
        {
            if(!visited[v])
            {
                visited[v]=true;
                q.push(v);
                d[v]=d[u]+1;
            }
        }
    }
    return d;
}


int main()
{
    int n,m,s;
    cin>>n>>m>>s;
    s--;
    vector<vll> adj(n);
    for(int x=0;x<m;x++)
    {
        ll a,b;
        cin>>a>>b;
        a--,b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vll d = bfs(adj,s);
    for(int x=0;x<n;x++)
    {
        cout<<d[x]<<" ";
    }
    cout<<endl;

    return 0;
}
