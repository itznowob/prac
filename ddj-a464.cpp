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
    cin.tie(nullptr);
    int n, m, k;
    while(cin >> n >> m >> k){
        vector<int> pr(n);
        for(int i = 0; i < n; i++){
            cin >> pr[i];
            if(pr[i] < 1) pr[i] = 1;
            if(pr[i] > 10000) pr[i] = 10000;
        }
        vector<int> dd(m);
        for(int i = 0; i < m; i++){
            cin >> dd[i];
        }
        const int MX = 10000;
        int INF = 1000000000;
        vector<int> bt(MX+1, INF), pd(MX+1, -1);
        for(int i = 0; i < n; i++){
            int x = pr[i];
            if(bt[x] > 0){
                bt[x] = 0;
                pd[x] = i+1;
            }
        }
        if(bt[k] == 0){
            cout << 0 << " " << pd[k] << "\n";
            continue;
        }
        int am = INF, ap = -1;
        for(int mo = 1; mo <= m; mo++){
            int d = dd[mo-1];
            for(int x = 1; x <= MX; x++){
                if(bt[x] <= mo-1){
                    int y = x + d;
                    if(y < 1) y = 1;
                    if(y > MX) y = MX;
                    if(bt[y] > mo){
                        bt[y] = mo;
                        pd[y] = pd[x];
                    }
                }
            }
            if(bt[k] <= mo){
                am = mo;
                ap = pd[k];
                break;
            }
        }
        if(ap == -1) 
		cout << -1 << "\n";
        else cout << am << " " << ap << "\n";
    }
}

