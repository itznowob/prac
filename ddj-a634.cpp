#include<bits/stdc++.h>
using namespace std;
bool check(const string &sub, const string &s){
    int i = 0, j = 0;
    while(i < sub.size() && j < s.size()){
        if(sub[i] == s[j])
            i++;
        j++;
    }
    return i == sub.size();
}
int main(){
    int N;
    cin >> N;
    vector<string> dna(N);
    for (int i = 0; i < N; i++){
        cin >> dna[i];
    }
    string base = dna[0];
    int n = base.size();
    int ans = 0;
    for (int mask = 1; mask < (1 << n); mask++){
        string sub = "";
        for (int i = 0; i < n; i++){
            if(mask & (1 << i)){
                sub.push_back(base[i]);
            }
        }
        bool bo = true;
        for (int i = 1; i < N; i++){
            if (!check(sub, dna[i])){
                bo = false;
                break;
            }
        }
        if(bo){
            ans = max(ans, (int)sub.size());
        }
    }
    cout << ans << '\n';
}
