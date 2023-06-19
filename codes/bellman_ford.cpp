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

vector<vll> edges;

vll bellman_ford(vector<vll> edges, ll n, ll m, ll s)
{
    vll dist(n);
    for(int x=0;x<n;x++)
    {
        dist[x]=INF;
    }
    dist[s]=0;

    for(int it=0;it<n;it++)
    {
        bool updated = false;
        for(int x=0;x<m;x++)
        {
            ll u = edges[x][0];
            ll v = edges[x][1];
            ll w = edges[x][2];
            ll new_dist = dist[u]+w;
            if(dist[v]>new_dist)
            {
                updated=true;
                dist[v]=new_dist;
                if(it==n-1)
                {
                    dist.clear();
                    return dist;
                }
            }
        }
        if(!updated)
        {
            break;
        }
    }
    return dist;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    edges.resize(m);
    for(int x=0;x<m;x++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        edges[x].push_back(u);
        edges[x].push_back(v);
        edges[x].push_back(w);
    }
    ll source = 0; // change source here if needed
    vll ans = bellman_ford(edges,n,m,source);

    for(int x=0;x<n;x++)
    {
        cout<<ans[x]<<" ";
    }
    cout<<endl;
    
    return 0;
}

/*

input : 
7 10
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 3 -2
4 6 -1
5 7 3
6 7 3

output : 
0 1 3 5 0 4 3 

*/