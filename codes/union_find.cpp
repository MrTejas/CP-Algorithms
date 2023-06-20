#include <bits/stdc++.h>
using namespace std;
// union find alorithm to detect cycles in an undirected graph
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
const ll MOD = 1e9+7; // 998244353;

ll find_parent(ll node, ll* parent)
{
    while(parent[node]!=node)
    {
        node = parent[node];
    }
    return node;
}

bool union_find_cycle(ll edges[][2], ll n, ll m)
{
    ll parent[n];
    for(int x=0;x<n;x++)
        parent[x]=x;
    bool cycle=false;
    for(int x=0;x<m;x++)
    {
        ll u = edges[x][0];
        ll v = edges[x][1];
        ll p_u = find_parent(u,parent);
        ll p_v = find_parent(v,parent);
        if(p_u==p_v)
        {
            cycle=true;
            break;
        }
        else
        {
            parent[u]=v;
        }
    }
    return cycle;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    ll edges[m][2];
    for(int x=0;x<m;x++)
    {
        ll u,v;
        u--,v--;
        cin>>u>>v;
        edges[x][0]=u;
        edges[x][1]=v;
    }
    bool cycle = union_find_cycle(edges,n,m);
    cout<<cycle<<endl;
    return 0;
}