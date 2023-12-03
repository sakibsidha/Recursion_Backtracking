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

const int N = 41;
char a[N][N];
bool vis[N][N];
int n, m, k;

/*
i think this is a wrong solution and testcases are weak.

3 5 0
#@..#
#ss.#
###xs

this should be possible, my code says it's not, still AC.
*/

bool BT(int r, int c, int cnt){
	if(cnt < 0) return false;
	if(a[r][c]=='#' || r < 0 || r >= n || c < 0 || c >= n || vis[r][c]) return false;
	vis[r][c] = true;
	if(a[r][c]=='x') return true;
	if(a[r][c]=='s'){
		return BT(r+1,c,cnt-1) || BT(r-1,c,cnt-1) || BT(r,c+1,cnt-1) || BT(r,c-1,cnt-1);
	}
	else return BT(r+1,c,cnt) || BT(r-1,c,cnt) || BT(r,c+1,cnt) || BT(r,c-1,cnt);
}

void solve(){
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			if(a[i][j]=='@'){
				bool f = BT(i,j,k/2);
				if(f){
					cout << "SUCCESS" << endl; return;
				}
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//int tc; cin >> tc;
	//while(tc--)
		solve();

	return 0;
}
