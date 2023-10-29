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

char a[4][4];
const int n = 4;

bool notok(int start_i, int i, int start_j, int j){
	unordered_map<char,int> M;
	for(int p = start_i; p <= i; ++p){
		for(int q = start_j; q <= 1; ++q){
			if(a[p][q]=='*') continue;
			else{
				M[a[p][q]]++;
				if(M[a[p][q]] > 1){
					return true;
				}
			}
		}
	}
	return false;
}

bool check(int i, int j){
	if(i <= 1 && j <= 1){
		if(notok(0,1,0,1)) return false;
	}
	else if(i <= 1 && j <= 3){
		if(notok(0,1,2,3)) return false;
	}
	else if(i <= 3 && j <= 1){
		if(notok(2,3,0,1)) return false;
	}
	else{
		if(notok(2,3,2,3)) return false;
	}
	unordered_map<char,int> M1, M2;
	for(int p = 0; p <= 3; ++p){
		if(a[i][p]!='*'){
			M1[a[i][p]]++;
			if(M1[a[i][p]] > 1){
				return false;
			}
		}
	}
	for(int p = 0; p <= 3; ++p){
		if(a[p][j]!='*'){
			M2[a[p][j]]++;
			if(M2[a[p][j]] > 1){
				return false;
			}
		}
	}
	return true;
}

void bt(int i, int j){
	if(i==3 && j==3 && a[i][j]!='*'){
		for(int p = 0; p < n; ++p){
			for(int q = 0; q < n; ++q){
				cout << a[p][q];
			}
			cout << endl;
		}
		return;
	}
	if(a[i][j]=='*'){
		for(char ch = '1'; ch <= '4'; ++ch){
			a[i][j] = ch;
			if(check(i,j)==true){
				if(i==3 && j==3) bt(i,j);
				else if(j < 3) bt(i,j+1);
				else bt(i+1,0);
				a[i][j] = '*';
			} 
			else{
				a[i][j] = '*';
				continue;
			}
		}
	}
	else{
		if(j < 3) bt(i,j+1);
		else bt(i+1,0);
	}
}

void solve(int cas = 0){
	cout << "Case #" << cas << ":" << endl;
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> a[i][j];
		}
	}
	bt(0,0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int tc; cin >> tc; int cas = 1;
	while(tc--){
		solve(cas); cas++;
	}

	return 0;
}
