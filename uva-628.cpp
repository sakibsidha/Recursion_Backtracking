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

string s;
vector<string> dict, ans;
int n, m;

void bt(int ptr){
	if(ptr==sz(s)){
		for(auto it: ans){
			cout << it;
		}
		cout << endl;
		return;
	}
	if(s[ptr]=='#'){
		for(int i = 0; i < n; ++i){
			ans.pb(dict[i]);
			bt(ptr+1);
			ans.pop_back();
		}
	}
	else{
		for(char i = '0'; i <= '9'; ++i){
			string str = "";
			str.pb(i);
			ans.pb(str);
			bt(ptr+1);
			ans.pop_back();
		}
	}
}

void solve(){
	while(cin >> n){
		dict.clear();
		for(int i = 0; i < n; ++i){
			string x; cin >> x;
			dict.pb(x);
		}
		cin >> m;
		cout << "--" << endl;
		for(int i = 1; i <= m; ++i){
			cin >> s;
			ans.clear();
			bt(0);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	//int tc; cin >> tc;
	//while(tc--)
		solve();

	return 0;
}
