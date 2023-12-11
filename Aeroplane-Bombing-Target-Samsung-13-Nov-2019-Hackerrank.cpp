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

int r;
int c = 5;
int a[100][5];
int tmp[100][5];
int ans = 0;

void copy(){
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			tmp[i][j] = a[i][j];
		}
	}
}

void bomb(int k){
	for(int i = k; i < min(k + 5, r); ++i){
		for(int j = 0; j < c; ++j){
			if(tmp[i][j]==2){
				tmp[i][j] = 0;
			}
		}
	}
}

void BT(int i, int j, int cnt){
	ans = max(ans,cnt);
	if(tmp[i][j]==2 || i < 0 || j < 0 || j > 4) return;
	if(tmp[i][j]==1){
		BT(i-1,j,cnt+1);
		BT(i-1,j-1,cnt+1);
		BT(i-1,j+1,cnt+1);
	}
	else{
		BT(i-1,j,cnt);
		BT(i-1,j-1,cnt);
		BT(i-1,j+1,cnt);
	}
}

void solve(){
	cin >> r;
	for(int i = 0; i < r; ++i){
		for(int j = 0; j < c; ++j){
			cin >> a[i][j];
		}
	}
	int res = 0;
	for(int i = 1; i <= max(1,(r-5)+1); ++i){
		copy();
		bomb(i-1);
		ans = 0;
		BT(r-1,2,0);
		res = max(ans,res);
		ans = 0;
		BT(r-1,3,0);
		res = max(ans,res);
		ans = 0;
		BT(r-1,1,0);
		res = max(ans,res);
	}
	cout << res << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc, t = 0; cin >> tc;
	while(tc-- && ++t){
		cout << "#" << t << " ";
		solve();
	}

	return 0;
}
