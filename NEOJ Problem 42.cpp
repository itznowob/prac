#include <bits/stdc++.h>
#define ll long long 
using namespace std;
void dfs(vector<vector<char>>& mp, ll x, ll y){
    mp[x][y] = '#';
    if (x + 1 < mp.size() && mp[x + 1][y] == '.') 
        dfs(mp, x + 1, y);
    if (x - 1 >= 0 && mp[x - 1][y] == '.') 
        dfs(mp, x - 1, y);
    if (y - 1 >= 0 && mp[x][y - 1] == '.') 
        dfs(mp, x, y - 1);
    if (y + 1 < mp[0].size() && mp[x][y + 1] == '.') 
        dfs(mp, x, y + 1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll tt;
    cin >> tt;
    while (tt--){
        ll x, y, ans = 0;
        cin >> x >> y;
        vector<vector<char>> mp(x, vector<char>(y));
        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                cin >> mp[i][j];
            }
        }
        for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                if (mp[i][j] == '.'){
                    dfs(mp, i, j);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
}
