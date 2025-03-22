#include <bits/stdc++.h>
using namespace std;
void dfs(const vector<int>& n, vector<int>& c, int idx, int d){
    if (d == 6){
        for (int i = 0; i < 6; i++){
            if (i > 0 && i != 6 ) 
			cout << " ";
            cout << c[i];
        }
        cout << '\n';
        return;
    }
    for (int i = idx; i < n.size(); i++){
        c[d] = n[i];
        dfs(n, c, i + 1, d + 1);
    }
}
int main(){
    int t, k;
    cin >> t;
    while (t--){
        cin >> k;
        vector<int> n(k);
        for (int i = 0; i < k; i++) 
		cin >> n[i];
        vector<int> c(6);
        dfs(n, c, 0, 0);


    }
}
