#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define endl "\n"

int r, c;
char a[100][100];
int v[100][100];

void setTozero(){
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			v[i][j] = 0;
		}
	}
}

void rec(int i, int j){
	if(i < 0 || j < 0 || i == r || j == c) return;
	if(a[i][j] != '@' || v[i][j] == 1) return;
	v[i][j] = 1;
	rec(i,j+1);
	rec(i,j-1);
	rec(i+1,j);
	rec(i-1,j);
	rec(i+1,j+1);
	rec(i-1,j-1);
	rec(i-1,j+1);
	rec(i+1,j-1);
}

void solve(){
    while(cin >> r >> c){
		if(r == 0) break;
		setTozero();
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				cin>> a[i][j];
			}
		}
		int cnt = 0;
		for(int i=0;i<r;++i){
			for(int j=0;j<c;++j){
				if(a[i][j]=='@' && v[i][j]==0){
					cnt++;
					rec(i,j);
				}
			}
		}
		cout << cnt << endl;
	}
}
    
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}
