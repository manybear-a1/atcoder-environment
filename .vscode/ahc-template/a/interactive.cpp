#pragma once
#include "template.cpp"
// for interactive problems
#ifdef _GLIBCXX_DEBUG
istringstream iss;
void query_input();
#endif
// Template for interactive problem output.
// you can change the parameters of the function as needed.
void query_output(/*vc<int> &output*/)
{
  // sample output:? n x_1 x_2 ... x_n
  // cout << "? " << output.size() << " ";
  // cout << output;
  // cout.flush();
#ifndef ONLINE_JUDGE
  // cerr << "? " << output.size() << " ";
  // cerr << output << endl;
#endif
#ifdef _GLIBCXX_DEBUG
  query_input();
#endif
}
// override cin to generate answer of the query without judge system so that you can debug the problem.
void query_input()
{
  // When solving interactive problems, you need to provide the answer in the format of a string to debug.
  // calculate the answer of the query here.

  // string input; // Answer of the query.

  // iss = istringstream(input);
  // // Redirect cin to the string stream for debugging
  // cin.rdbuf(iss.rdbuf());
}