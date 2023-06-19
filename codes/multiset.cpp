#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
const ll MOD = 1e9+7; // 998244353;

void printset(set<ll> s)
{
    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

void printmultiset(multiset<ll> s)
{
    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

int main()
{
    multiset<ll> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(4);
    ms.insert(1);
    ms.insert(2);
    ms.insert(5);
    printmultiset(ms);
    ms.erase(1);
    printmultiset(ms);
    // cout<<endl;
    return 0;
}