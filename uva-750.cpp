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

int pre_x, pre_y;
int a[8][8];
vector<vi> ans;

bool valid(int r, int c){
	for(int i = 0; i < 8; ++i){
		if(a[r][i]==1) return false;
		if(a[i][c]==1) return false;
	}
	int tmp_i = r, tmp_j = c;
	while(tmp_i >= 0 && tmp_i < 8 && tmp_j >= 0 && tmp_j < 8){
		if(a[tmp_i][tmp_j]==1) return false;
		tmp_i++; tmp_j++;
	}
	tmp_i = r, tmp_j = c;
	while(tmp_i >= 0 && tmp_i < 8 && tmp_j >= 0 && tmp_j < 8){
		if(a[tmp_i][tmp_j]==1) return false;
		tmp_i++; tmp_j--;
	}
	tmp_i = r, tmp_j = c;
	while(tmp_i >= 0 && tmp_i < 8 && tmp_j >= 0 && tmp_j < 8){
		if(a[tmp_i][tmp_j]==1) return false;
		tmp_i--; tmp_j--;
	}
	tmp_i = r, tmp_j = c;
	while(tmp_i >= 0 && tmp_i < 8 && tmp_j >= 0 && tmp_j < 8){
		if(a[tmp_i][tmp_j]==1) return false;
		tmp_i--; tmp_j++;
	}
	return true;
}

void BT(int j,int cnt,vi& v){
	if(cnt==8){
		ans.pb(v);
		return;
	}
	if(j==pre_y-1){
		v.pb(pre_x);
		BT(j+1,cnt+1,v);
		v.pop_back();
	}
	for(int k = 0; k < 8; ++k){
		if(valid(k,j)){
			a[k][j] = 1;
			v.pb(k+1);
			BT(j+1,cnt+1,v);
			v.pop_back();
			a[k][j] = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc;
	for(int p = 1; p <= tc; ++p){
		cin >> pre_x >> pre_y;
		for(int i = 0; i < 8; ++i){
			for(int j = 0; j < 8; ++j){
				if(i==pre_x-1 && j == pre_y-1) a[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		vi v;
		BT(0,0,v);
		cout << "SOLN       COLUMN" << endl;
		cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
		int k = 1;
		for(int i = 0; i < sz(ans); ++i){
			for(int j = 0; j < sz(ans[i]); ++j){
				if(!j) cout << ((k <= 9)?" ":"") <<  k++ << "      ";
				cout << ans[i][j] << ((j==sz(ans[i])-1)?"\n":" ");
			}
			ans[i].clear();
		}
		if(p!=tc) cout << endl;
	}
	return 0;
}
