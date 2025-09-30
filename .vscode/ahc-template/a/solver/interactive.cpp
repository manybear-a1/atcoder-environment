#pragma once
#include "../template.cpp"
#include "../util.cpp"
struct query_calculator
{
  int count_query = 0;
  int query_calc()
  {
    return 1;
  }
  // apply the response to the internal state
  // return false if the interaction should end
  // return true to continue the interaction
  bool applyresponse(vc<int> response, int count_query_)
  {
    // apply the response to the internal state
    this->count_query = count_query_;
  }
};

void solve_query()
{
  bool condition = true;
  int count_query = 0;
  query_calculator qc;
  while (condition)
  {
    auto res = query_read();
    condition = qc.applyresponse(res, count_query);
    if (!condition)
      break;
    auto ans = qc.query_calc();
    query_output(ans);
    count_query++;
  }
}