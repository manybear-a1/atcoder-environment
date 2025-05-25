// #ifndef ONLINE_JUDGE
// #define _GLIBCXX_DEBUG 1 //[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
// #endif

#ifdef ONLINE_JUDGE
#define NDEBUG
#include <atcoder/all>
#endif
#include <bits/stdc++.h>
// # include <boost/multiprecision/cpp_dec_float.hpp>
// # include <boost/multiprecision/cpp_int.hpp>
// # include <boost/rational.hpp>
// namespace mp = boost::multiprecision;
// // 任意長整数型
// using Bint = mp::cpp_int;
// // 仮数部が32桁(10進数)の浮動小数点数型
// using Real32 = mp::number<mp::cpp_dec_float<32>>;
// // 仮数部が1024桁(10進数)の浮動小数点数型
// using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// // ついでに有理数型
// using Rat = boost::rational<Bint>;
using namespace atcoder;

using namespace std;
using ll = long long;
using ld = long double;
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
void solve()
{
  //  cout << ans << endl;
}
int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  // ref:https://rsk0315.hatenablog.com/entry/2020/05/09/170315
  solve();
  return 0;
}
