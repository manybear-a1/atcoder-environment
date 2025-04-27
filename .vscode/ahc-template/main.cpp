// #ifndef ONLINE_JUDGE
// #define _GLIBCXX_DEBUG 1 //[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意 ABC311Eのサンプル4みたいなデバック中のTLEは防げないので注意
// #endif
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
using mint = modint998244353;
// using mint = modint1000000007;
// using mint = static_modint<10>;//使うときはコメントアウトを外す
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
// ref:https://qiita.com/sorachandu/items/041169d34b9f9b99bcf7#timer-%E6%99%82%E9%96%93%E8%A8%88%E6%B8%AC%E7%94%A8class
//  std::chronoを利用した時間計測用クラス
class Timer
{
  chrono::system_clock::time_point start;

public:
  Timer() : start(chrono::system_clock::now()) {}

  double count()
  {
    chrono::duration<double> Time_ = chrono::system_clock::now() - start;
    return Time_.count();
  }

  bool is_under(double x)
  {
    return (this->count()) < x;
  }
};
Timer timer;
// ref:https://qiita.com/sorachandu/items/041169d34b9f9b99bcf7#timer-%E6%99%82%E9%96%93%E8%A8%88%E6%B8%AC%E7%94%A8class
//  std::uniform_int_distributionを利用した一様乱数生成クラス
class Random_Gen
{
  mt19937 engine;
  uniform_int_distribution<int64_t> dist;

public:
  // Constructor [l,r]で生成する値の範囲を指定
  Random_Gen() : engine(0) {}
  Random_Gen(int64_t l, int64_t r) : engine(0), dist(l, r) {}

  // 現在の生成する値の範囲をstd::pairで返す
  pair<int64_t, int64_t> get_range()
  {
    return make_pair(dist.min(), dist.max());
  }
  // 生成する値の範囲を[l,r]に変更する
  void set_range(int64_t l, int64_t r)
  {
    uniform_int_distribution<int64_t>::param_type Param(l, r);
    dist.param(Param);
  }
  // [l,r]内の一様分布の整数を返す
  int64_t gen()
  {
    return dist(engine);
  }
  int64_t operator()() { return gen(); }
};
// for interactive problems
#ifdef _GLIBCXX_DEBUG
istringstream iss;
#endif
void query(vc<int> &v)
{
  cout << "? " << v.size() << " ";
  cout << v;
  cout.flush();
#ifndef ONLINE_JUDGE
  cerr << "? " << v.size() << " ";
  cerr << v << endl;
#endif
#ifdef _GLIBCXX_DEBUG
  string s; // Answer of the query.
  iss = istringstream(s);
  cin.rdbuf(iss.rdbuf());
#endif
}
struct Action
{
  friend ostream &operator<<(ostream &o, const Action &a)
  {
    // o << "\n";
    return o;
  }
};
class State
{
public:
  vc<Action> actions;
  int calc_score()
  {
    return 0;
  }
  friend ostream &operator<<(ostream &o, const State &state)
  {
    o << state.actions.size() << endl;
    rep(i, state.actions.size())
    {
      o << state.actions[i];
    }
    return o;
  }
};
class Greedy
{
public:
  State solve_all()
  {
    State state;
    solve_partial(state);
    solved_state = state;
    return state;
  }
  // 部分問題を解く。
  // そのままビームサーチや焼きなましに使えるように作る
  void solve_partial(State &state)
  {
    return;
  }
  const State &get_solved_state()
  {
    return solved_state;
  }

private:
  Random_Gen rand_greedy;
  State solved_state;
};
class SimulatedAnnealing
{
public:
  // 自動で貪欲法による初期解を生成します。
  SimulatedAnnealing(Greedy &greedy)
  {
    this->greedy = greedy;
    this->greedy.solve_all();
    this->solved_state = this->greedy.get_solved_state();
  }
  State simulate()
  {
    double TIME_LIMIT = 1.8; // 制限時間
#ifdef _GLIBCXX_DEBUG
    TIME_LIMIT = 9.0;
    int max_files = 10;
    int interval = 1;
#endif
#ifndef ONLINE_JUDGE
    TIME_LIMIT = 4.0;
    int count_loop = 0;
    int count_accepted = 0;
#endif
    double start_temp = 50, end_temp = 10; // 適当な値を入れる（後述）
    while (true)
    { // 時間の許す限り回す(timerライブラリを使用)
      if (!timer.is_under(TIME_LIMIT))
        break;

      State new_state = this->solved_state;
      modify(new_state);
      int new_score = new_state.calc_score();
      int pre_score = this->solved_state.calc_score();

      // 温度関数
      double temp = start_temp + (end_temp - start_temp) * (timer.count()) / TIME_LIMIT;
      // 遷移確率関数(最大化の場合)
      double prob = exp((new_score - pre_score) / temp);
#ifndef ONLINE_JUDGE
      count_loop++;
#endif
#ifdef _GLIBCXX_DEBUG
      if (count_loop <= interval * max_files && count_loop % interval == 0)
      {
        string filename = "sa/output";
        filename += to_string(count_loop / interval);
        filename += ".txt";
        ofstream ofs(filename);
        ofs << this->solved_state;
      }
#endif
      if (prob > (rand() % INF) / (double)min(RAND_MAX, INF))
      { // 確率probで遷移する
        this->solved_state = new_state;
#ifndef ONLINE_JUDGE
        count_accepted++;
#endif
      }
    }
#ifndef ONLINE_JUDGE
    cerr << "l/a" << " " << count_loop << " " << count_accepted << endl;
    cerr << double(count_loop) / (double)count_accepted << endl;
#endif
    return this->solved_state;
  }

private:
  Greedy greedy;
  State solved_state;
  void modify(State &state)
  {
    // ここに焼きなましの操作を実装する
    return;
  }
};
class BeamSearch
{
  // TODO:いつか実装する
public:
  BeamSearch(Greedy &greedy, int beam_width) : greedy(greedy), beam_width(beam_width)
  {
    // 初期解を生成
    nodes.resize(beam_width);
  }
  State search() {}

private:
  Greedy greedy;
  int beam_width;
  vc<State> nodes;
};
int main()
{
  // TODO:テンプレートのデバッグ
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  // ref:https://rsk0315.hatenablog.com/entry/2020/05/09/170315
  cin; // Input here!

  timer = Timer();
#ifdef _GLIBCXX_DEBUG
  ofstream coutdbg("output.txt");
  flush(cout);
  cout.close();
  cout.rdbuf(coutdbg.rdbuf());
#endif
  // 貪欲法
  Greedy greedy;
  State state = greedy.solve_all();

  // 焼きなまし
  // Greedy greedy;
  // SimulatedAnnealing sa(greedy);
  // State state = sa.simulate();
  //

  // ビームサーチ
  //  Greedy greedy;
  //  BeamSearch beam_search(greedy, 10);
  //  State state = beam_search.search();

#ifdef _GLIBCXX_DEBUG
  ofstream coutgreedy("greedy_output.txt");
  coutgreedy << state;
  coutgreedy.close();
#endif
  // cout << state.actions.size() << endl;

  cout << state;
  flush(cout);
#ifdef _GLIBCXX_DEBUG
  coutdbg.close();
#endif
  //  cout << ans << endl;
  return 0;
}
