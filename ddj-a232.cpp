#include <bits/stdc++.h>
#define ll long long 
#define ul unsigned long long
#define um unordered_map
#define f first
#define s second
#define fr front()
#define PB push_back
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, a;
    while(cin >> n >> m >> a){
        vector<bool> obs(n*m, false);
        for(int i = 0; i < a; i++){
            int x, y;
            cin >> x >> y;
            obs[x*m+y] = true;
        }
        const int MOD = 1000000007;
        vector<int> dp(m, 0);
        if (obs[0]){
    		dp[0] = 0;
		} 
		else{
    		dp[0] = 1;
		}
        for(int j = 1; j < m; j++){
            if(obs[j]) dp[j] = 0;
            else dp[j] = dp[j-1];
        }
        for(int i = 1; i < n; i++){
            if(obs[i*m]) dp[0] = 0;
            for(int j = 1; j < m; j++){
                if(obs[i*m+j]) dp[j] = 0;
                else dp[j] = (dp[j] + dp[j-1]) % MOD;
            }
        }
        cout << dp[m-1] <<'\n';
    }
}
