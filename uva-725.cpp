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

const int N = 1e5+10;
vi v = {1,2,3,4,5,6,7,8,9,0};
vector<vector<string>> res(N);
bool yes[N];

void permute(){
	do{
		int val_1 = 0, val_2 = 0;
		for(int i = 0; i < 10; ++i){
			if(i >= 0 && i < 5) val_1 = val_1*10 + v[i];
			else val_2 = val_2*10 + v[i];
		}
		auto makestr = [&] (int start, int end){
			string s;
			for(int i = start; i < end; ++i) s.pb(v[i]+'0');
			return s;
		};
		if(val_1%val_2==0){
			yes[val_1/val_2] = true;
			string s = makestr(0,5) + " / " + makestr(5,10);
			res[val_1/val_2].pb(s);
		}
	} while(next_permutation(all(v)));
}

void solve(){
	int num;
	int ln = 0;
	while(cin >> num && num){
		cout << ((ln)?"\n":""); ln = 1;
		if(yes[num]==true){
			for(auto it: res[num]){
				cout << it << " = " << num << endl;
			}
		}
		else cout << "There are no solutions for " << num << "." << endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	permute();
	//int tc; cin >> tc;
	//while(tc--)
		solve();

	return 0;
}
