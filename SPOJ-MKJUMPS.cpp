#include <bits/stdc++.h>
using namespace std;

int a[10][10];
int vis[10][10];
int n, ans;

// tanima apu (el.duivel)
int kx[] = { -2, -2, -1, -1, 1, 1, 2, 2}; // Knights Move
int ky[] = { -1, 1, -2, 2, -2, 2, -1, 1}; // Knights Move

void bt(int r, int c, int cnt){
	for(int i = 0; i < 8; ++i){
		int x = r + kx[i];
		int y = c + ky[i];
		if(x >= 10 || x < 0 || y >= 10 || y < 0 || vis[x][y] == 1 || a[x][y] == 0) continue;
		else{
			vis[x][y] = 1;
			bt(x,y,cnt+1);
			vis[x][y] = 0;
		}
	}
	ans = max(ans,cnt);
}

void solve(){
	int cas = 1;
	while(cin >> n && n){
		memset(a,0,sizeof(a));
		memset(vis,0,sizeof(vis));
		int f = 0, start_r = 0, start_c = 0, total = 0;
		for(int i = 0; i < n; ++i){
			int x, y; cin >> x >> y;
			for(int j = x; j < x+y; ++j){
				a[i][j] = 1;
				if(f==0){ start_r = i; start_c = j; f = 1; }
				total++;
			}
		}
		ans = 0;
		vis[start_r][start_c] = 1;
		bt(start_r,start_c,1);
		cout << "Case " << cas << ", " << total-ans <<  ((total-ans==1)?" square":" squares") << " can not be reached." << endl;
		cas++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();

	return 0;
}
