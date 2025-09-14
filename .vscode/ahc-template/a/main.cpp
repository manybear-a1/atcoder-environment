// Template for competitive programming (atcoder heuristic contest)
// this template is only for marathon problems. not for long term use.
#include "template.cpp"
#include "util.cpp"
#include "state.cpp"
#include "solver/solver.cpp"
#include "input.cpp"

int main()
{
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  // ref:https://rsk0315.hatenablog.com/entry/2020/05/09/170315
#ifdef _GLIBCXX_DEBUG
  ofstream coutdbg("output.txt");
  OStreamRedirect redirect_cout(cout, coutdbg);
#endif
  input();
  solve();
  return 0;
}
