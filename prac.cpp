#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define um unordered_map
#define F first
#define S second
#define fr front()
#define endl '\n' 
using namespace std;
int main(){
    int n;
    scanf("%d", &n);
    vector<int> da(n);
    for (int i = 0; i < n; i++){
        int y, m, d;
        scanf("%d %d %d", &y, &m, &d);
        da[i] = y * 10000 + m * 100 + d;
    }
    sort(da.begin(), da.end());
    for (int key : da) {
        int y = key / 10000;
        int m = (key / 100) % 100;
        int d = key % 100;
        printf("%d %d %d\n", y, m, d);
    }
}
