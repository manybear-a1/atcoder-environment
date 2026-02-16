#pragma once
#include "../template.cpp"
#include "../util.cpp"
#include "../state.cpp"
#include "greedy.cpp"
// #include "simulated_annealing.cpp"
// #include "beam_search.cpp"
// #include "interactive.cpp"
void solve()
{

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

  // Interactive Problem
  // solve_query();
  // cout << state.actions.size() << endl;
  // TODO: check the output format of the problem.
  cout << state;
  flush(cout);
}