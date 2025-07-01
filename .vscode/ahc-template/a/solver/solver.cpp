#pragma once
#include "../template.cpp"
#include "../util.cpp"
#include "../state.cpp"
#include "greedy.cpp"
// #include "simulated_annealing.cpp"
// #include "beam_search.cpp"
void solve()
{

#ifdef _GLIBCXX_DEBUG
  ofstream coutdbg("output.txt");
  OStreamRedirect redirect_cout(cout, coutdbg);
#endif

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
}