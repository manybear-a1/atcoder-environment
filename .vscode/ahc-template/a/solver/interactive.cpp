#pragma once
#include "../template.cpp"
#include "../util.cpp"
#include "../state.cpp"
#include "../interactive.cpp"
extern GlobalState global_state;
struct query_calculator
{
  int count_query = 0;
  State state;
  vector<int> query_calc(int count_query)
  {
    return {1};
  }
};
struct playout_solver
{
  int count_query = 0;
  State state;
  Random rnd;
  vector<int> query_calc(int count_query)
  {
    int best_parameter = 0;
    double best_score = -INF;
    rep(i, 10){
      double score = playout(count_query, i);
      if(score > best_score){
        best_score = score;
        best_parameter = i;
      }
    }
    return {best_parameter};
  }
  // playoutの実装
  double playout(int count_query, int parameter)
  {
    bool condition = true;
    int cq = count_query;
    query_calculator qc;
    qc.count_query = cq;
    qc.state = state;
    
    while (condition)
    {
      auto ans = qc.query_calc(cq);

      simulate(ans, qc.state);
      count_query++;
    }
    return qc.state.calc_score();
  }
  // simulate one turn of the game with the given move and update the state accordingly
  void simulate(const pair<int, int> &move, State &state)
  {
  }
};

void solve_query()
{
  bool condition = true;
  int count_query = 0;
  query_calculator qc;
  while (condition)
  {
    query_read(qc.state);
    auto ans = qc.query_calc(count_query);
    query_output(ans);
    count_query++;
  }
}