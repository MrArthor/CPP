#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
// using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define pb push_back
#define ppb pop_back
//#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define mset(a , b) memset(a , b , sizeof(a))
#define ll long long int

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
bool revsort(ll a, ll b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
ll combination(ll n, ll r, ll m, ll *fact, ll *ifact) {ll val1 = fact[n]; ll val2 = ifact[n - r]; ll val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))
/*--------------------------------------------------------------------------------------------------------------------------*/




void solve() {
  ll n;
  cin >> n;

  vector<vector<ll>> v;
  for (int i = 0; i < n; i++) {
    ll sz;
    cin >> sz;
    vector<ll> k(sz);
    for (int j = 0; j < sz; j++) {
      cin >> k[j];
    }
    v.pb(k);
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < v[i].size(); j++) {
  //     cout << v[i][j] << " ";
  //   } cout << endl;
  // }

  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll len = 1;
    ll ind = v[i].size();
    //ans += ind;
    for (int j = 1; j < v[i].size(); j++) {
      if (v[i][j] < v[i][j - 1]) {
        ind = j;
        break;
      }
      len++;
    }
    if (ind == v[i].size()) {
      if (n == 1) {
        cout << 0 << endl;
        return;
      }
      len = v[i].size();
      continue;
    }
    ll cur = 1, cnt = len;
    for (int j = ind + 1; j < v[i].size(); j++) {
      if (v[i][j] < v[i][j - 1]) {
        ans += min(len, cur);
        //cout << "len " << len << endl;
        ans += cnt + cur;
        cnt += cur;
        len = cur;
        cur = 0;
      }
      cur++;

    }
    ans += min(len, cur);
    ans += cnt + cur;
    //ans += v[i].size();
  }

  ll sum = v[0].size();
  for (int i = 1; i < n; i++) {
    ans += sum + v[i].size();
    sum += v[i].size();
  }

  cout << ans << endl;

}

int main()
{
  fastio();

  //cout << 111 << endl;
  ll t;
  cin >> t;
  //t = 1;
  int tc = 1;
  while (t--) {
    //cout << "Case #" << tc << ": ";
    solve();
    tc++;
    //cout << endl;
  }


  return 0;
}