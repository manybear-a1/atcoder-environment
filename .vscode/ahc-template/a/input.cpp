#pragma once
#include "template.cpp"
#include "util.cpp"

// TODO:Store input data here in global variables
// you have to use extern to refer these variables;

struct GlobalState
{
};
GlobalState global_state;
void input()
{
  // cin >> N;
  // A.resize(N);
  // cin >> A;
  static_assert(false, "input() not implemented!");
}