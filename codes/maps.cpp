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
    map<string,int> marksMap;
    // marksMap.insert({"Tejas",100});
    marksMap["Tejas"]=100;
    marksMap["Tejas1"]=98;
    marksMap["Tejas2"]=12;
    marksMap["Tejas3"]=10;

    marksMap.insert({"Lala",10});
    marksMap.erase("Tejas1");
    auto psi=marksMap.find("Tejas");
    cout<<(*psi).first << "-"<<(*psi).second<<endl;

    for(auto i = marksMap.begin(); i!=marksMap.end();i++)
    {
        cout<<(*i).first<<" "<<(*i).second<<endl;
    }

    return 0;
}