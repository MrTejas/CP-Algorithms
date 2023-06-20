#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
const ll MOD = 1e9+7; // 998244353;

ll n,m;
vector<pair<ll,pll>> edges;
vector<vll> mst; // (n-1) x 2 array


ll find_parent(ll node, ll* parent)
{
    while(parent[node]!=node)
    {
        node = parent[node];
    }
    return node;
}

bool union_find_cycle()
{
    ll parent[n];
    for(int x=0;x<n;x++)
        parent[x]=x;
    bool cycle=false;
    for(int x=0;x<mst.size();x++)
    {
        ll u = mst[x][0];
        ll v = mst[x][1];
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


// returns the indices of edges in the mst
vll kruskals()
{
    sort(edges.begin(), edges.end()); // sort in ascending order
    vll ans;
    for(int x=0;x<m;x++)
    {
        ll u = edges[x].second.first;
        ll v = edges[x].second.second;
        mst.push_back({u,v});
        ans.push_back(x);
        if(union_find_cycle())
        {
            mst.pop_back();
            ans.pop_back();
        }
        if(mst.size()==n-1)
        {
            break;
        }
    }
    return ans;
    // can return mst also if needed (without weights)
}

int main()
{
    cin>>n>>m;
    edges.resize(m);
    for(int x=0;x<m;x++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        edges[x]={w,{u,v}};
    }
    vll ed = kruskals();
    cout<<"MST edges are :\n";
    for(int x=0;x<ed.size();x++)
    {
        cout<<edges[ed[x]].second.first + 1<<" "<<edges[ed[x]].second.second + 1<<endl;
    }
    
    return 0;
}

/*
input :
6 9
5 4 9
5 1 4
4 1 1
4 3 5
1 2 2
4 2 3
3 2 3
3 6 8
2 6 7

output :
MST edges are :
4 1
1 2
3 2
5 1
2 6

*/