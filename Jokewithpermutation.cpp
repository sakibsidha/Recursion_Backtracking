/*
ACM ICPC 2014–2015, Northeastern European Regional Contest
St. Petersburg – Barnaul – Tbilisi – Tashkent, December 7, 2014
Problem J
*/
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

int n;
vi vis(51);
int got_one = 0;

void bt(vi& ans, string s, int in){
	if(got_one) return;
	if(in==sz(s)){
		if(sz(ans)==n){
			for(int i = 0; i < n; ++i){
				cout << ans[i] << ((i==n-1) ? "\n" : " ");
			}
			got_one = 1;
		}
		return;
	}
	if(in < sz(s)-1){
		int a = s[in]-'0';
		if(a==0){
			bt(ans,s,in+1);
		}
		int b = (s[in]-'0')*10+(s[in+1]-'0');
		if(b <= n){
			if(vis[b]==0){
				ans.pb(b);
				vis[b] = 1;
				bt(ans,s,in+2);
				vis[b] = 0;
				ans.pop_back();
			}
		}
		if(vis[a]==0){
			ans.pb(a);
			vis[a] = 1;
			bt(ans,s,in+1);
			vis[a] = 0;
			ans.pop_back();
		}
	}
	else{
		int a = s[in]-'0';
		if(a==0){
			bt(ans,s,in+1);
		}
		if(vis[a]==0){
			vis[a]=1;
			ans.pb(a);
			bt(ans,s,in+1);
			ans.pop_back();
			vis[a]=1;
		}
	}
}

void solve(){
	
	freopen("joke.in","r",stdin);
	freopen("joke.out","w",stdout);
	
	string s;
	while(cin >> s){
		got_one = 0;
		n = (sz(s) > 9) ? (sz(s)-9)/2+9 : sz(s);
		auto set_vis = [&]{
			for(int i = 1; i <= n; ++i){
				vis[i] = 0;
			}
		};
		set_vis();
		vi ans;
		bt(ans,s,0);
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
