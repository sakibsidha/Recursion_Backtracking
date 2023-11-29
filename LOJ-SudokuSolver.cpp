#include <bits/stdc++.h>
using namespace std;
#define sz(x) (int) x.size()

int a[9][9];
const int n = 9;
int f = 0;
int vis[81];
vector<pair<int,int>> v;

void print(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cout << a[i][j];
		}
		cout << endl;
	}
}

bool valid(int r, int c, int val){
	// checking row-column
	for(int i = 0; i < 9; ++i){
		if(a[r][i]==val) return false;
		if(a[i][c]==val) return false;
	}
	
	// checking 3x3
	r = (r/3)*3;
	c = (c/3)*3;
	for(int i = r; i < r+3; ++i){
		for(int j = c; j < c+3; ++j){
			if(a[i][j]==val) return false;
		}
	}
	return true;
}

// r4m1m bhai, https://youtu.be/5F9YzkpnaRw?si=QnlwgcvtdRd1KBk1

int heuristic(){
	int mn = INT_MAX, idx = -1;
	for(int i = 0; i < sz(v); ++i){
		if(!vis[i]){
			int cnt = 0;
			int r = v[i].first, c = v[i].second;
			for(int j = 1; j <= 9; ++j){
				if(valid(r,c,j)) cnt++;
			}
			if(cnt < mn){
				mn = cnt; idx = i;
			}
		}
	}
	return idx; 
}

void BT(int idx, int cnt){
	if(f) return;
	if(cnt==sz(v)){
		print();
		f = 1;
		return;
	}
	int r = v[idx].first, c = v[idx].second;
	for(int i = 1; i <= 9; ++i){
		if(valid(r,c,i)){
			a[r][c] = i;
			vis[idx] = true;
			BT(heuristic(),cnt+1);
			a[r][c] = 0;
			vis[idx] = false;
		}
	}
}

void solve(){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			char ch; cin >> ch;
			if(ch=='.'){
				a[i][j] = 0;
				v.push_back({i,j});
			}
			else a[i][j] = ch-'0';
		}
	}
	f = 0;
	BT(heuristic(),0);
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	v.clear();
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	int cas = 1;
	while(tc--){
		cout << "Case " << cas  << ":" << endl;
		solve();
		cas++;
	}

	return 0;
}
