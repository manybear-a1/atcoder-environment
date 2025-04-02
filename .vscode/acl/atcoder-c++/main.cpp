// #ifndef ONLINE_JUDGE
// #define _GLIBCXX_DEBUG 1 //[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
// #endif
#include <bits/stdc++.h>

#ifdef ONLINE_JUDGE
#include <atcoder/all>
#endif
using namespace atcoder;

using namespace std;
using ll = long long;
ll INF = 2e18;
using P = pair<ll, ll>;
#define pb push_back
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reprev(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define reps(i, n) for (ll i = 1; i <= (n); i++)
#define for_(i, a, b) for (ll i = (a); i < (b); i++)
#define all(v) v.begin(), v.end()
template <typename T>
inline bool chmin(T &a, const T &b)
{
  bool c = a > b;
  if (c)
    a = b;
  return c;
}
template <typename T>
inline bool chmax(T &a, const T &b)
{
  bool c = a < b;
  if (c)
    a = b;
  return c;
}
template <typename T>
inline T ceil(T a, T b) { return (a + (b - 1)) / b; }
using mint = modint998244353;
// using mint = modint1000000007;
// using mint = static_modint<10>;//使うときはコメントアウトを外す
template <typename T>
using vc = vector<T>;
template <class T>
istream &operator>>(istream &i, vc<T> &v)
{
  rep(j, (ll)size(v)) i >> v[j];
  return i;
}
template <class T>
ostream &operator<<(ostream &o, const vc<T> &v)
{
  rep(j, (ll)size(v))
  {
    if (j)
      o << " ";
    o << v[j];
  }
  o << endl;
  return o;
}
int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  // ref:https://rsk0315.hatenablog.com/entry/2020/05/09/170315
  //  cout << ans << endl;
  return 0;
}
