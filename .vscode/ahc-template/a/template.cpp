#pragma once
#ifdef ONLINE_JUDGE
#define NDEBUG
#include <atcoder/all>
#endif
#include <bits/stdc++.h>
using namespace atcoder;

using namespace std;
int INF = 1e9;
using P = pair<int, int>;
#define pb push_back
#define rep(i, n) for (int i = 0; i < (n); i++)
#define reprev(i, n) for (int i = (n) - 1; i >= 0; i--)
#define reps(i, n) for (int i = 1; i <= (n); i++)
#define for_(i, a, b) for (int i = (a); i < (b); i++)
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
template <typename T>
using vc = vector<T>;
template <class T>
istream &operator>>(istream &i, vc<T> &v)
{
  rep(j, (int)size(v)) i >> v[j];
  return i;
}
template <class T>
ostream &operator<<(ostream &o, const vc<T> &v)
{
  rep(j, (int)size(v))
  {
    if (j)
      o << " ";
    o << v[j];
  }
  o << endl;
  return o;
}