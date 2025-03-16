#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<char>> ma;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while(tt--){
        cin >> n >> m;
        ma.assign(n, vector<char>(m));
        int sx = -1, sy = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> ma[i][j];
                if(ma[i][j] == 'K'){
                    sx = i; sy = j;
                }
            }
        }
        vector<vector<int>> ds(n, vector<int>(m, -1));
        queue<pair<int,int>> qu;
        ds[sx][sy] = 0;
        qu.push({sx, sy});
        int an = -1;
        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
        while(!qu.empty()){
            auto [x, y] = qu.front(); qu.pop();
            if(ma[x][y] == '@'){
                an = ds[x][y];
                break;
            }
            for(int i = 0; i < 4; i++){
                int nx = x + dx[i], ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && ma[nx][ny] != '#' && ds[nx][ny] == -1){
                    ds[nx][ny] = ds[x][y] + 1;
                    qu.push({nx, ny});
                }
            }
        }
        if(an == -1)
            cout << "= =\"" << "\n";
        else
            cout << an << "\n";
    }
}

