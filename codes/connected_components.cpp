#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
const ll MOD = 1e9+7; // 998244353;
vll cc;


// takes input an adjacency list of a graph and returns shortest distance of each node from 's'
void dfs(vector<vll> adj, ll u, bool* visited)
{
    // cout<<"ck2\n";
    visited[u]=1;
    cc.push_back(u);
    for(ll v : adj[u])
    {
        if(!visited[v])
        {
            dfs(adj,v,visited);
        }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
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
    int index = 0;
    for(int x=0;x<n;x++)
    {
        if(visited[x]!=1)
        {
            dfs(adj,x,visited);
            cout<<"Component "<<index+1<<endl;
            for(int y=0;y<cc.size();y++)
            {
                cout<<cc[y]+1<<" ";
            }
            cout<<endl;
            index++;
            cc.clear();
        }
    }
    
    cout<<"Total "<<index<<" connected Components\n";


    return 0;
}

/*
input : 
10 9
1 6
1 5
1 2
1 3
2 3
2 4
8 9
10 8
9 10


output : 
Component 1
1 6 5 2 3 4 
Component 2
7 
Component 3
8 9 10 
Total 3 connected Components
*/
