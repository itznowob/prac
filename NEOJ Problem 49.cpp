#include <bits/stdc++.h>
#define ll long long 
#define ul unsigned long long
#define um unordered_map 
#define F first
#define S second
#define fr front()
using namespace std;
ll box(um<ll, list<ll>>& vl, um<ll, ll>& memo, ll bx){
    if (memo.find(bx) != memo.end()){
        return memo[bx];
    }
    ll c = 1;
    for (ll x : vl[bx]){
        c += box(vl, memo, x);
    }
    memo[bx] = c;
    return c;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll tt;
    cin >> tt;
    while(tt--){
        um<ll, ll> mp;
        um<ll, list<ll>> vl;
        um<ll, ll> memo;
        ll n, m;
        cin >> n >> m;
        ll a, b;
        for (int i = 0; i < m; i++){
            cin >> a >> b;
            vl[a].push_back(b);
        }
        ll q;
        cin >> q;
        while(q--){
            ll y;
            cin >> y;
            cout << box(vl, memo, y) << '\n';
        }
    }
}
