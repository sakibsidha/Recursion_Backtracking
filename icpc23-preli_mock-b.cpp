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

const ll N = 1e4+10;
ll cnt = 0, f = 0;
ll dp[N];

void setdp(){
	for(int i = 0; i < N; ++i){
		dp[i] = -1;
	}
}

ll fun(ll n, ll p, ll k){
	if(f==1) return 0;
	if(dp[n]!=-1){
		if(cnt + dp[n] < k){
			cnt += dp[n];
			return dp[n];
		}
	}
	if(n < p) return 0;
	dp[n] = 0;
	for(ll i = n-1; i >= n-p; --i){
		cnt++;
		if(cnt==k){
			cout << "" << n << " " << i << endl;
			f = 1;
			return 0;
		}
		dp[n] += fun(i,p,k)+1;
		if(f==1) return 0;
	}
	return dp[n];
}

void solve(int cas = 0){
	setdp(); cnt = f = 0;
	ll n, p, k; cin >> n >> p >> k;
	cout << "Case " << cas << ": ";
	fun(n,p,k);
	if(f==0) cout << "Invalid" << endl;
}

int main(){    
	ios::sync_with_stdio(0);    
	cin.tie(0);
	
	int tc; cin >> tc; int cas = 1;   
	while(tc--){  
		solve(cas);
		cas++;
	}
	
	return 0;
}

// I never got to submit this, I was only learning recursion-backtracking at the moment, so I was happy to come up with a
// solution using recursion + memorisation. Probably not enough to pass the tests, given that seniors from my varsity
// got 10+ WA/TLE before AC, still..
