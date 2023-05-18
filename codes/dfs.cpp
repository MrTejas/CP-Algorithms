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
void dfs(vector<vll> adj, ll u, bool* visited, ll* time_in, ll* time_out, ll timer)
{
    cout<<"visited node "<<u+1<<endl;
    visited[u]=1;
    time_in[u]=timer++;
    for(ll v : adj[u])
    {
        if(!visited[v])
        {
            dfs(adj,v,visited,time_in,time_out,timer);
        }
    }
    time_out[u]=timer++;
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

    bool visited[n]={0};
    ll time_in[n]={0};
    ll time_out[n]={0};
    ll timer = 0;
    dfs(adj,s,visited,time_in,time_out,timer);

    return 0;
}

/*
input : 
17 16 1
1 2
2 3
3 4
4 5
5 6
5 7
3 8
2 9
9 10
9 12
10 11
1 13
13 14
13 17
14 15
15 16

output:
visited node 1
visited node 2
visited node 3
visited node 4
visited node 5
visited node 6
visited node 7
visited node 8
visited node 9
visited node 10
visited node 11
visited node 12
visited node 13
visited node 14
visited node 15
visited node 16
visited node 17
*/
