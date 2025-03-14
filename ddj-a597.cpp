#include <bits/stdc++.h>
#define ll long long 
#define ul unsigned long long
#define um unordered_map 
#define F first
#define S second
#define fr front()
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c;
    cin >> n >> c;
    vector<ll> dp(c+1, -1);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        vector<pair<int,int>> v;
        v.push_back({0,0});
        for(int j = 0; j < k; j++){
            int a, b;
            cin >> a >> b;
            v.push_back({a,b});
        }
        vector<ll> nd(c+1, -1);
        for(int j = 0; j <= c; j++){
            if(dp[j] == -1) 
			continue;
            for(auto &p : v){
                int co = p.second, hp = p.first;
                if(j + co <= c)
                    nd[j+co] = max(nd[j+co], dp[j] + hp);
            }
        }
        dp = nd;
    }
    ll an = 0;
    for(int i = 0; i <= c; i++){
        an = max(an, dp[i]);
    }
    cout << an;
}
