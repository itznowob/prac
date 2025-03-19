#include <bits/stdc++.h>
#define ll long long 
#define ul unsigned long long
#define um unordered_map 
#define f first
#define s second
#define fr front()
#define PB push_back
using namespace std;
void up(tuple<int, vector<ll>> &ft, int i, ll v){
    int n = get<0>(ft);
    vector<ll> &tr = get<1>(ft);
    for (; i <= n; i += i & (-i)){
        tr[i] = max(tr[i], v);
    }
}
ll qy(tuple<int, vector<ll>> &ft, int i){
    ll r = 0;
    vector<ll> &tr = get<1>(ft);
    for (; i > 0; i -= i & (-i)){
        r = max(r, tr[i]);
    }
    return r;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> h(n), c(n);
    for (int i = 0; i < n; i++){
        cin >> h[i];
    }
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    vector<ll> cp = h;
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    int m = cp.size();
    auto ft = make_tuple(m, vector<ll>(m + 1, 0));
    ll an = 0;
    for (int i = 0; i < n; i++){
        int id = lower_bound(cp.begin(), cp.end(), h[i]) - cp.begin() + 1;
        ll bs = qy(ft, id - 1);
        ll cr = bs + c[i];
        up(ft, id, cr);
        an = max(an, cr);
    }
    cout << an << '\n';
}
