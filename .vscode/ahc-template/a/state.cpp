#pragma once
#include "template.cpp"
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
private:
  vc<Action> actions;

public:
  // only for beam search
  int hash = 0;

  int calc_score() const
  {
    // TODO: implement here for individual problem
    assert(false && "State::calc_score() not implemented!");
    int score = -INF;
    return score;
  }
  // TODO: Implement output format for each problem
  friend ostream &operator<<(ostream &o, const State &state)
  {
    // Example: output number of actions, then each action
    // o << state.actions.size() << endl;
    // rep(i, state.actions.size())
    // {
    //   o << state.actions[i];
    // }
    static_assert(false, "State::operator<<() not implemented!");
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
  // returns if applied successfully
  bool apply(int data)
  {
    actions.push_back({data});
    // Update  if necessary
    return true;
  }
};
