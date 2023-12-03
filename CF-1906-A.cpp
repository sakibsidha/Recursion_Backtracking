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

char a[3][3];
set<string> ans;
bool vis[3][3];
int dir[8][2] = {{-1,0},{1,0},{0,1},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};

void BT(int r, int c, string s){
    if(sz(s)==3){
        ans.ins(s);
        return;
    }
    for(int i = 0; i < 8; ++i){
        int X = r + dir[i][0];
        int Y = c + dir[i][1];
        if(X >= 0 && X < 3 && Y >= 0 && Y < 3 && !vis[X][Y]){
            vis[X][Y] = true;
            s.pb(a[X][Y]);
            BT(X,Y,s);
            vis[X][Y] = false;
            s.pop_back();
        }
    }
}

void solve(){
    char ch = 'C';
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> a[i][j];
            ch = min(ch,a[i][j]);
        }
    }
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
           if(a[i][j]==ch){
               string s;
               s.pb(ch); vis[i][j] = true;
               BT(i,j,s);
               memset(vis,0,sizeof(vis));
           }
       } 
    }
    cout << *ans.begin() << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //int tc; cin >> tc;
    //while(tc--)
        solve();

    return 0;
}
