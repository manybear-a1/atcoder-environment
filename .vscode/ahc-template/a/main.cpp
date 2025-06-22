// Template for competitive programming (atcoder heuristic contest)
// this template is only for marathon problems. not for long term use.
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
// ref(窃盗先) :https://atcoder.jp/contests/ahc048/submissions/66624955
class Random
{
public:
  Random() : state_(3141592653589793238ULL) {}

  double RandomDouble(double a, double b)
  {
    Update();
    const double r = state_ * kScale_;
    return a + (b - a) * r;
  }

  int RandomInt(int a, int b)
  {
    return static_cast<int>(RandomDouble(a, b));
  }

  int RandomIntInclusive(int a, int b)
  {
    return RandomInt(a, b + 1);
  }

private:
  uint64_t state_;

  // 2^(-64)
  static constexpr double kScale_ = 1.0 / 18446744073709551616.0;

  void Update()
  {
    // xorshift
    state_ ^= state_ >> 13;
    state_ ^= state_ << 7;
    state_ ^= state_ >> 17;
  }
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
// TODO:Store input data here in global variables
// int N;
// vc<int> A;
struct Action
{
  // TODO: implement here for individual problem
  //  int data;
  friend ostream &operator<<(ostream &o, const Action &a)
  {
    static_assert(false, "Action::operator<<() not implemented!");
    // o << data << "\n";
    return o;
  }
};
class State
{
public:
  vc<Action> actions;
  // only for beam search
  int hash = 0;

  int calc_score() const
  {
    // TODO: implement here for individual problem
    assert(false && "State::calc_score() not implemented!");
    int score = 0;
    return score;
  }
  // TODO: Implement output format for each problem
  friend ostream &operator<<(ostream &o, const State &state)
  {
    // Example: output number of actions, then each action
    o << state.actions.size() << endl;
    rep(i, state.actions.size())
    {
      o << state.actions[i];
    }
    return o;
  }
  friend bool operator<(const State &a, const State &b)
  {
    return a.calc_score() < b.calc_score();
  }
  friend bool operator>(const State &a, const State &b)
  {
    return a.calc_score() > b.calc_score();
  }
  apply(int data)
  {
    actions.push_back({data});
    // Update  if necessary
  }
};
class Greedy
{
public:
  State solve_all()
  {

    rep(i, 100)
    {
      State state;
      solved_state = solve_partial(state);
    }
    return solved_state;
  }
  State solve_partial(State &state, int seed = 0 /*If you are going to use beam search, don't make this method deterministic.*/)
  {
    // implement greedy algorithm here
    static_assert(false, "Greedy::solve_partial() not implemented!");
    return state;
  }
  const State &get_solved_state() const
  {
    return solved_state;
  }

private:
  State solved_state;
};
class SimulatedAnnealing
{
public:
  SimulatedAnnealing(Greedy &greedy_)
  {
    this->greedy = greedy_;
    this->greedy.solve_all();
    this->solved_state = this->greedy.get_solved_state();
  }
  State simulate()
  {
    // 問題の制限時間を確認すること！！！
    double TIME_LIMIT = 1.9;
#ifdef _GLIBCXX_DEBUG
    TIME_LIMIT = 4.0;
    // debug output config
    // max files to output
    int max_files = 10;
    // interval for debug output
    int interval = 1;
#endif
#ifndef ONLINE_JUDGE
#ifndef _GLIBCXX_DEBUG
    TIME_LIMIT = 4.0;
#endif
    // statistics for debug
    int count_loop = 0;
    int count_accepted = 0;
    cerr << "score before SA:" << this->solved_state.calc_score() << endl;
    cerr << "state before SA:" << this->solved_state << endl;
#endif
    double start_temp = 50, end_temp = 10;
    State now_state = this->solved_state;
    int now_score = now_state.calc_score();
    int best_score = now_score;
    while (true)
    {
      if (!timer.is_under(TIME_LIMIT))
        break;

      State new_state = this->solved_state;
      modify(new_state);
      int new_score = new_state.calc_score();
      int diff = new_score - now_score; // diff = modify(new_state);

      // temperature
      double temp = start_temp + (end_temp - start_temp) * (timer.count()) / TIME_LIMIT;
      // probability
      double prob = exp((diff) / temp);
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
      if (prob > rand_SA.RandomDouble(0, 1))

      {

        swap(now_state, new_state);
        now_score = new_score;
        if (new_score > best_score)
        {
          best_score = new_score;
          this->solved_state = now_state;
        }
#ifndef ONLINE_JUDGE
        count_accepted++;
#endif
      }
      else
      {
        // modify(new_state);
      }
    }
#ifndef ONLINE_JUDGE
    cerr << "l/a" << " " << count_loop << " " << count_accepted << endl;
    if (count_accepted != 0)
      cerr << "accept rate" << " " << double(count_accepted) / (double)count_loop << endl;
    else
      cerr << "accept rate" << " " << 0.0 << endl;
    cerr << "score after SA:" << now_state.calc_score() << endl;
    cerr << "state after SA:" << now_state << endl;
#endif
    return this->solved_state;
  }

private:
  Greedy greedy;
  State solved_state;
  Random rand_SA;
  void modify(State &state)
  {
    assert(false && "SimulatedAnnealing::modify() not implemented!");
    return;
  }
};
class BeamSearch
{
public:
  BeamSearch(Greedy &greedy_, int beam_width_) : greedy(greedy_), beam_width(beam_width_)
  {
  }

  State search()
  {
    // 1. create initial state
    State initial;
    vector<State> current_beam = {initial};

    int max_steps = 100;
    for (int step = 0; step < max_steps; ++step)
    {
      vector<State> next_candidates;
      unordered_set<int> seen_hashes;

      // 2. expand each state in the current beam
      for (const State &state : current_beam)
      {
        // 3. generate next states
        for (int seed = 0; seed < 5; ++seed)
        {
          State next = state;

          // TODO: implement the logic to generate next states
          greedy.solve_partial(next, seed);

          // Remove duplicate states by hash
          if (seen_hashes.count(next.hash))
            continue;
          seen_hashes.insert(next.hash);
          next_candidates.push_back(next);
        }
      }

      // 4. prune the next candidates to keep only the best ones
      if (next_candidates.empty())
      {
        assert(false && "next_candidates is empty");
      }
      partial_sort(next_candidates.begin(), next_candidates.begin() + min(beam_width, (int)next_candidates.size()), next_candidates.end(), greater<>());

      if ((int)next_candidates.size() > beam_width)
        next_candidates.resize(beam_width);

      current_beam = next_candidates;
    }

    // 4. return the best state from the current beam
    return *max_element(current_beam.begin(), current_beam.end(), [](const State &a, const State &b)
                        { return a.calc_score() < b.calc_score(); });
  }

private:
  Greedy greedy;
  int beam_width;
};
#ifdef _GLIBCXX_DEBUG
class OStreamRedirect
{
  std::ostream &os;
  std::streambuf *old_buf;

public:
  OStreamRedirect(std::ostream &os_, std::ostream &new_stream)
      : os(os_), old_buf(os_.rdbuf(new_stream.rdbuf())) {}
  ~OStreamRedirect()
  {
    os.rdbuf(old_buf);
  }
};
#endif
int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  // ref:https://rsk0315.hatenablog.com/entry/2020/05/09/170315

#ifdef _GLIBCXX_DEBUG
  ofstream coutdbg("output.txt");
  OStreamRedirect redirect_cout(cout, coutdbg);
#endif
  // Receive inputs here
  // cin >> N;
  // A.resize(N);
  // cin >> A;

  timer = Timer();
  // greedy
  Greedy greedy;
  State state = greedy.solve_all();

  // Simulated Annealing
  // Greedy greedy;
  // SimulatedAnnealing sa(greedy);
  // State state = sa.simulate();
  //

  //  Beam Search
  //  Greedy greedy;
  //  BeamSearch beam_search(greedy, 10);
  //  State state = beam_search.search();

#ifdef _GLIBCXX_DEBUG
  ofstream coutgreedy("greedy_output.txt");
  coutgreedy << state;
  flush(coutgreedy);
#endif
  // cout << state.actions.size() << endl;
  // TODO: check the output format of the problem.
  cout << state;
  flush(cout);
  return 0;
}
