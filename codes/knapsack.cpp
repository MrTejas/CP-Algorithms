#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
const ll MOD = 1e9+7; // 998244353;

ll max(ll a, ll b)
{
    return a>b?a:b;
}


ll knapsack(ll w, ll i, ll* wt, ll* val, ll** dp)
{
    if(w==0 || i==-1)
    {
        // not possible to add any item (weight = 0, num items = 0)
        return 0;
    }
    if(dp[i][w]!=-1)
    {
        // already calculated
        return dp[i][w];
    }

    if(wt[i]>w)
    {
        // not possible to add the ith item
        // leave the item and look at knapsack(w,i-1)
        return (dp[i][w] = knapsack(w,i-1,wt,val,dp));
    }
    else 
    {
        // ith item can be added to the knapsack
        // 2 cases (1 - add the item) (2 - dont add the item)
        ll val1 = val[i]+knapsack(w-wt[i],i-1,wt,val,dp);
        ll val2 = knapsack(w,i-1,wt,val,dp);
        return (dp[i][w] = max(val1,val2));
    }
}



int main()
{
    ll n,w;
    cin>>n>>w;
    ll wt[n],val[n];
    for(int x=0;x<n;x++)
    {
        cin>>wt[x]>>val[x];
    }

    ll** dp;
    dp = new ll*[n];
    for(int x=0;x<n;x++)
    {
        dp[x]=new ll[w+1];
    }
    for(int x=0;x<n;x++)
    {
        for(int y=0;y<w+1;y++)
        {
            dp[x][y]=-1; // not calculated
        }
    }

    // for(int x=0;x<n;x++)
    // {
    //     for(int y=0;y<w+1;y++)
    //     {
    //         cout<<dp[x][y]<<" ";
    //     }
    //     cout<<endl;
    // }

    ll ans = knapsack(w,n-1,wt,val,dp);
    cout<<ans<<endl;

    return 0;
}