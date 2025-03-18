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
    int tt;
    cin >> tt;
    while(tt--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> g(n);
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vector<int> co(n,-1);
        bool bi = true;
        for(int i = 0; i < n; i++){
            if(co[i] == -1){
                queue<int> q;
                q.push(i);
                co[i]=0;
                while(!q.empty()){
                    int c = q.front(); q.pop();
                    for(auto nxt : g[c]){
                        if(co[nxt]==-1){
                            co[nxt] = co[c]^1;
                            q.push(nxt);
                        }
                        else if(co[nxt]==co[c]){
                            bi = false;
                            break;
                        }
                    }
                    if(!bi) 
					break;
                }
            }
            if(!bi) 
			break;
        }
        if(bi){
            cout << "NORMAL." << "\n";
        }
        else{
            cout << "RAINBOW." << "\n";
        }
    }
}
