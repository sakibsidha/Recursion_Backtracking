/**
 *    author: sakibsidha
 *    created: 26-08-2023 17:36:30
**/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
using vii = vector<pair<int,int>>;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define sz(y) (int) y.size()
#define endl "\n"

const int N = 100;
vi prime(N,1);

void small_sieve(){
	prime[0] = prime[1] = 0;
	for(int i = 2; i*i <= N; ++i){
		if(prime[i]==1){
			for(int j = i*i; j <= N; j+=i) prime[j] = 0;
		}
	}
}

int n;

void gen(int num, vi& sub, unordered_map<int,int>& m,vector<vi>& ans,vector<vi>& v){
	if(sz(sub)==n){
		if(prime[sub[n-1]+sub[0]]==1) ans.pb(sub);
		return;
	}
	for(int i = 0; i < sz(v[num]); ++i){
		if(m[v[num][i]]==0){
			sub.pb(v[num][i]);
			m[v[num][i]] = 1;
		}
		else continue;
		gen(sub[sz(sub)-1],sub,m,ans,v);
		m[sub.back()] = 0;
		sub.pop_back();
	}
}

void soln(vi& in){
	for(int k = 0; k < sz(in); ++k){
		vector<vi> v(17);
		n = in[k];
		for(int i = 1; i <= n; ++i){
			int j = (i%2)? 2 : 1;
			for(; j <= n; j+=2) if(prime[i+j]==1) v[i].pb(j);
		}
		vi sub;
		sub.pb(1);
		unordered_map<int,int> m;
		vector<vi> ans;
		m[1] = 1;
		gen(1,sub,m,ans,v);
		cout << "Case " << k+1 << ":" << endl;
		for(int i = 0; i < sz(ans); ++i){
			for(int j = 0; j < sz(ans[i]); ++j){
				cout << ans[i][j];
				if(j!=(sz(ans[i])-1)) cout << " ";
			}
			cout << endl;
		}
		if(k!=(sz(in)-1)) cout << endl;
	}
}

void solve(){
	vi in;
	while(cin >> n){
		in.pb(n);
	}
	soln(in);
}
    
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	
    small_sieve();
	solve();
    
    return 0;
}
