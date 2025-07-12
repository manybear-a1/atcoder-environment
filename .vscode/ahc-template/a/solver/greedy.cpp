#pragma once
#include "../template.cpp"
#include "../util.cpp"
#include "../state.cpp"
// extern int N;
// extern vc<int>A;
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