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

ll power(ll base, ll power) {
  ll res = 1;
  while(power) {
    if(power%2) {
    	res = (res*base);
    } 
    base = (base*base);
    power >>= 1;

  }
  return res;
}	

bool isSet(ll num, int bit) {
  ll mask = power(2, bit);
  return (mask & num) != 0;
}

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a%b);
}

ll LCM(ll a, ll b) {
  return (1ll*a*b) / gcd(a, b);
}

void sol () {
  int n, k; cin >> n >> k;
  vi arr(k);
  for(auto &it : arr) cin >> it;
  /*
    using principle of inclusion and exclusion
    -> using bitmasking to generate all the subsets!
  */

  ll end = power(2, k);
  int ans = 0;   
  for(ll i = 1; i < end; i++) {
  	ll lcm = 1ll, cnt = 0ll;
    bool breaked = false;
    for(int j = 0; j < k; j++) {
      if(isSet(i, j)) {
        lcm = LCM(lcm, arr[j]);
        if(lcm > mod) {
          breaked = true;
          break;
        } 
        cnt++;
      }
    }
    if(breaked) continue;
    if(cnt % 2) ans += (n / lcm);
    else ans -= (n / lcm);
  }
  cout << n - ans << nline;
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
  sol();
  cerr<<"TIME : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<nline;
  return 0;
}