#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
using ll = long long;
using ld = long double;
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vb = vector<bool>;
template<class T>
using indexed_set = tree<T,null_type,less<T>,rb_tree_tag,
tree_order_statistics_node_update>;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define all(x) (x).begin(),(x).end()
#define sz(y) (int) y.size()
#define endl "\n"
#define sim template < class c 
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {  
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {  
  *this << "[";  
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define db(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int a[101][101], vis[101][101], dp[101][101], r, c;
string s;
int rec(int i, int j, int last_i, int last_j){
	if(i < 0 || j < 0 || i >= r || j >= c) return 0;
	if(vis[i][j]==1){
		if(a[i][j] < a[last_i][last_j]) return dp[i][j];
		else return 0;
	}
	vis[i][j] = 1;
	if((last_i==-69 && last_j==-69) || a[i][j] < a[last_i][last_j]){
		int down = rec(i+1,j,i,j);
		int up = rec(i-1,j,i,j);
		int right = rec(i,j+1,i,j);
		int left = rec(i,j-1,i,j);
		dp[i][j] += max(down,max(up,max(right,left)));
		return dp[i][j];
	}
	else{
		vis[i][j] = 0;
		return 0;
	}
}

void solve(){
	cin >> s >> r >> c;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> a[i][j];
			vis[i][j] = 0; dp[i][j] = 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			if(vis[i][j]==0) ans = max(ans,rec(i,j,-69,-69));
			else ans = max(ans,dp[i][j]);
		}
	}
	cout << s << ": " << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	while(tc--)
		solve();

	return 0;
}
