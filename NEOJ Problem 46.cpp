#include <bits/stdc++.h>
using namespace std;
int f(int N, int x, int y, int t){
    int lx = max(0, x - t), rx = min(N - 1, x + t);
    int ly = max(0, y - t), ry = min(N - 1, y + t);
    int sx = rx - lx + 1, sy = ry - ly + 1;
    return sx * sy;
}
int ff(int N, int x1, int y1, int x2, int y2, int t){
    int lx = max({0, x1 - t, x2 - t});
    int rx = min({N - 1, x1 + t, x2 + t});
    int ly = max({0, y1 - t, y2 - t});
    int ry = min({N - 1, y1 + t, y2 + t});
    if(rx < lx || ry < ly) 
	return 0;
    return (rx - lx + 1) * (ry - ly + 1);
}
int fff(int N, int x1, int y1, int x2, int y2, int x3, int y3, int t){
    int lx = max({0, x1 - t, x2 - t, x3 - t});
    int rx = min({N - 1, x1 + t, x2 + t, x3 + t});
    int ly = max({0, y1 - t, y2 - t, y3 - t});
    int ry = min({N - 1, y1 + t, y2 + t, y3 + t});
    if(rx < lx || ry < ly) 
	return 0;
    return (rx - lx + 1) * (ry - ly + 1);
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; 
    cin >> T;
    while(T--){
        int N; 
        cin >> N;
        int r1, r2, y1, y2, b1, b2;
        for(int i = 0; i < 3; i++){
            char c; 
            int a, b;
            cin >> c >> a >> b;
            if(c == 'R'){ 
			r1 = a; r2 = b;
		}
            else if(c == 'Y'){
			 y1 = a; y2 = b; 
}
            else if(c == 'B'){ 
			b1 = a; b2 = b; 
}
        }
        char X; 
        cin >> X;
        int tm = 0;
        vector<int> v ={ r1, N - 1 - r1, r2, N - 1 - r2, y1, N - 1 - y1, y2, N - 1 - y2, b1, N - 1 - b1, b2, N - 1 - b2 };
        for(auto u : v) 
		tm = max(tm, u);
        int mx = 0;
        for(int t = 0; t <= tm; t++){
            int AR = f(N, r1, r2, t);
            int AY = f(N, y1, y2, t);
            int AB = f(N, b1, b2, t);
            int RY = ff(N, r1, r2, y1, y2, t);
            int RB = ff(N, r1, r2, b1, b2, t);
            int YB = ff(N, y1, y2, b1, b2, t);
            int R3 = fff(N, r1, r2, y1, y2, b1, b2, t);
            int rr = AR - RY - RB + R3;
            int yy = AY - RY - YB + R3;
            int bb = AB - RB - YB + R3;
            int oy = RY - R3;
            int pu = RB - R3;
            int gy = YB - R3;
            int dk = R3;
            int cu = 0;
            if(X=='R') 
			cu = rr;
            else if(X=='Y') 
			cu = yy;
            else if(X=='B') 
			cu = bb;
            else if(X=='O') 
			cu = oy;
            else if(X=='P') 
			cu = pu;
            else if(X=='G') 
			cu = gy;
            else if(X=='D') 
			cu = dk;
            mx = max(mx, cu);
        }
        cout << mx << "\n";
    }
}
