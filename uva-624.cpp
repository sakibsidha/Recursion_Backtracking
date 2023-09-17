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

vector<vi> subsets;
int n, k;
int Max;
void func(vi& sub,int ind, vi& v,int sum){
	if(ind==n){
		if(sum<=k){
			subsets.pb(sub);
			Max = max(sum,Max);
		}
		return;
	}
	func(sub,ind+1,v,sum);
	sub.pb(v[ind]);
	sum+=v[ind];
	func(sub,ind+1,v,sum);
	sum-=(sub.back());
	sub.pop_back();
}

void solve(){
	while(cin >> k >> n){
		subsets.clear();
		vector<int> v(n);
		for(int i = 0; i < n; ++i) cin >> v[i];
		vi sub;
		int sum = 0;
		Max = 0;
		func(sub,0,v,sum);
		int var = 0, l = -1;
		for(int i = 0; i < sz(subsets); ++i){
			int tot = accumulate(all(subsets[i]),0);
			if(tot==Max){
				if(sz(subsets[i]) > l){
					l  = sz(subsets[i]);
					var = i;
				}
			}
		}
		for(int i = 0; i < sz(subsets[var]); ++i) cout << subsets[var][i] << " ";
		cout << "sum:" << Max << endl;
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
