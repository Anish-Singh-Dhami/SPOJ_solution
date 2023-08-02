/*  
    Talent and begin good at something thing is one part and other (probably more important) part
    is having confidence and conviction that you have the ability to do that thing. 
    And then puting in the time, effort & pracitce and not giving up when things get difficult.
*/
#include <bits/stdc++.h>
using namespace std;
 
#define fastIO() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define nline '\n'
#define mod 1000000007
#define inf 1e18
#define ff first
#define PI 3.141592653589793238462
#define ss second
#define pii pair<int, int>
#define vpii vector<pii>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define ppb pop_back
#define rep(i, init, n) for (int i = init; i < (int)n; i++)
#define MOD 998244353

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using u64 = uint64_t;
using u128 = __uint128_t;
 
void pyes() {cout << "YES" << nline;}
void pno() {cout << "NO" << nline;}
void noans() {cout << "-1" << nline;} 
void allUpper(string &s) {
  transform(s.cbegin(), s.cend(), s.begin(), [](auto &c){
    return toupper(c);
  });
} 

ll modulo(ll n) {
  return (n % mod + mod) % mod;
}

ll add(ll a, ll b) {
  return modulo(modulo(a) + modulo(b));
}

ll mul(ll a, ll b) {
  return modulo(modulo(a) * modulo(b));
}

ll sub(ll a, ll b) {
  return modulo(modulo(a) - modulo(b) + mod);
}

void sol () {
  string text, pattern; cin >> text >> pattern;
  ll p = 26;
  int n = text.size(), m = pattern.size();
  if (m > n) {
    cout << "Not Found\n";
    cout << nline;
    return;
  }
  // vll power(n, 0);
  ll power[n] = {0};
  power[0] = 1;
  for(int i = 1; i < n; i++) {
  	power[i] = mul(power[i-1], p);
  }

  ll patternHash = 0;
  for(int i = 0; i < m; i++) {
  	patternHash = add(patternHash, mul(pattern[i] - 'a' + 1, power[i]));
  }

  // vll hash(n+1, 0);
  ll hash[n+1] = {0};
  for(int i = 0;i < n; i++) {
  	hash[i+1] = add(hash[i], mul(text[i] - 'a' + 1, power[i]));
  }

  vi ans;
  for(int i = 0; i < n - m + 1; i++) {
  	int currHash = sub(hash[i+m], hash[i]);
  	if(currHash == mul(patternHash, power[i])) {
  		ans.pb(i+1);
  	}
  }

  if(ans.empty()) {
  	cout << "Not Found\n";
  } else {
  	cout << ans.size() << nline;
  	for(auto &it : ans) cout << it << " ";
    cout << nline;
  }
  cout << nline;
}
 
void RepSolution() {
  int t; cin >> t;
  while(t--) {
    sol();
  }
}
 
int main(){
  fastIO();
  #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt", "w", stderr);
  #endif
  RepSolution();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}