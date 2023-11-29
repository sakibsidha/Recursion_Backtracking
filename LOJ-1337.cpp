#include <bits/stdc++.h>
using namespace std;

char a[501][501];
bool vis[501][501];
int r, c, cnt;

void BT(int i, int j, vector<pair<int,int>>& tmp){
    if(i < 0 || j < 0 || i >= r || j >= c || a[i][j] == '#' || vis[i][j]) return;
    vis[i][j] = true;
    tmp.push_back({i,j});
    if(a[i][j]=='C') cnt++;
    BT(i,j+1,tmp);
    BT(i,j-1,tmp);
    BT(i+1,j,tmp);
    BT(i-1,j,tmp);
}

void solve(){
    int q; cin >> r >> c >> q;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            cin >> a[i][j];
        }
    }
    
    // pre-calc
    map<pair<int,int>,int> M;
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j){
            if(!vis[i][j]){
                cnt = 0;
                vector<pair<int,int>> tmp;
                BT(i,j,tmp);
                for(auto it: tmp) M[it] = cnt;
            }
        }
    }
    
    while(q--){
        int x, y; cin >> x >> y; x--; y--;
        cout << M[{x,y}] << endl;
    }
    memset(vis,0,sizeof(vis));
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    int cas = 1;
    while(tc--){
        cout << "Case " << cas << ":" << endl;
        cas++;
        solve();
    }

    return 0;
}
