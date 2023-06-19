#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pld;
typedef vector<ll> vll;
typedef vector<ld> vld;
const ll MOD = 1e9+7; // 998244353;

int main()
{
    set<ll,greater<ll>> s;
    s.insert(1);
    s.insert(5);
    s.insert(2);
    s.insert(-2);
    s.erase(2);
    for(auto i : s)
    {
        cout<<i<<" ";
    }
    cout<<"\nSet size = "<<s.size()<<endl;

    return 0;
}