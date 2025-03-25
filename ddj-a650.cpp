#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define um unordered_map
#define F first
#define S second
#define fr front()
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    const int md = 1000000007;
    vector<int> dp(n,0), nd(n,0);
    dp[0] = 1;
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        int r = k % n;
        fill(nd.begin(), nd.end(), 0);
        for(int j = 0; j < n; j++){
            nd[j] = (nd[j] + dp[j]) % md;
            int t = (j + r) % n;
            nd[t] = (nd[t] + dp[j]) % md;
        }
        dp = nd;
    }
    int ans = dp[0] - 1;
    if(ans < 0) ans += md;
    cout << ans % md << '\n';
}
