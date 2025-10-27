#pragma once
#include "../template.cpp"
#include "../util.cpp"
#include "../state.cpp"
#include "../input.cpp"
extern GlobalState global_state;
// extern int N;
// extern vc<int>A;
class Greedy
{
public:
  State solve_all()
  {
    solved_state = solve_partial();
    while (timer.is_under(1.9))
    {
      State state = solve_partial();
      chmax(solved_state, state);
    }
#ifdef _GLIBCXX_DEBUG
    ofstream coutgreedy("greedy_output.txt");
    coutgreedy << solved_state;
    flush(coutgreedy);
#endif
    return solved_state;
  }

  State solve_partial()
  {
    // implement greedy algorithm here
    static_assert(false, "Greedy::solve_partial() not implemented!");
    return State();
  }

  const State &get_solved_state() const
  {
    return solved_state;
  }

private:
  State solved_state;
  Random rand;
  Timer timer;
  mt19937 rng_shuffle;
};