#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }
        vector<ll> op(n);
        for (int i = 0; i < n; i++){
            cin >> op[i];
        }
        sort(op.begin(), op.end());
        auto cw = [&](ll m) -> bool{
            vector<ll> sp(n);
            for (int i = 0; i < n; i++){
                sp[i] = a[i] + m * b[i];
            }
            sort(sp.begin(), sp.end());
            int wn = 0, i = 0, j = 0;
            while(i < n && j < n){
                if(sp[i] > op[j]){
                    wn++;
                    i++; 
					j++;
                } 
				else{
                    i++;
                }
            }
            return wn >= k;
        };
        
        if(cw(0)){
            cout << 0 << '\n';
            continue;
        }
        ll lo = 0, hi = 1;
        const ll LM = 1000000000000LL;
        while(hi <= LM && !cw(hi)){
            hi *= 2;
        }
        if(hi > LM && !cw(hi)){
            cout << -1 << '\n';
            continue;
        }
        ll an = -1;
        while(lo <= hi){
            ll md = lo + (hi - lo) / 2;
            if(cw(md)){
                an = md;
                hi = md - 1;
            } 
			else{
                lo = md + 1;
            }
        }
        cout << an << '\n';
    }
}


