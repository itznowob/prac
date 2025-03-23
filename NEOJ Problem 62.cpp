#include <bits/stdc++.h>
using namespace std;
int ar[9][9];
bool row[9][10], col[9][10], blo[9][10];
bool solve(int r, int c){
    if(r == 9) 
        return true;
    if(c == 9) 
        return solve(r + 1, 0);
    if(ar[r][c] != 0) 
        return solve(r, c + 1); 

    int block = (r / 3) * 3 + (c / 3);
    for(int num = 1; num <= 9; num++){
        if(!row[r][num] && !col[c][num] && !blo[block][num]){
            ar[r][c] = num;
            row[r][num] = col[c][num] = blo[block][num] = true;
            if(solve(r, c + 1))
                return true;
            ar[r][c] = 0;
            row[r][num] = col[c][num] = blo[block][num] = false;
        }
    }
    return false;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(s.size() != 81){
            cout << "No solution." << '\n';
            continue;
        }
        bool ok = true;
        for(char ch : s){
            if(ch != '.' && (ch < '1' || ch > '9')){
                ok = false;
                break;
            }
        }
        if(!ok){
            cout << "No solution." << '\n';
            continue;
        }
        memset(ar, 0, sizeof(ar));
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(blo, false, sizeof(blo));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char ch = s[i * 9 + j];
                if(ch == '.'){
                    ar[i][j] = 0;
                } else {
                    int num = ch - '0';
                    ar[i][j] = num;
                    int block = (i / 3) * 3 + (j / 3);
                    if(row[i][num] || col[j][num] || blo[block][num]){
                        ok = false;
                    }
                    row[i][num] = col[j][num] = blo[block][num] = true;
                }
            }
        }
        if(!ok){
            cout << "No solution." << '\n';
            continue;
        }
        if(!solve(0, 0)){
            cout << "No solution." << '\n';
            continue;
        }
        bool solved = true;
        vector<int> ve;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                ve.push_back(ar[i][j]);
                if(ar[i][j] == 0)
                    solved = false;
            }
        }
        if(!solve){
            cout << "No solution." << '\n';
        } 
		else{
            for(auto x : ve)
                cout << x;
            cout << '\n';
        }
    }
}

