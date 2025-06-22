#pragma once
// for interactive problems
#ifdef _GLIBCXX_DEBUG
istringstream iss;
#endif
void query(vc<int> &v)
{
  cout << "? " << v.size() << " ";
  cout << v;
  cout.flush();
#ifndef ONLINE_JUDGE
  cerr << "? " << v.size() << " ";
  cerr << v << endl;
#endif
#ifdef _GLIBCXX_DEBUG
  string s; // Answer of the query.
  iss = istringstream(s);
  cin.rdbuf(iss.rdbuf());
#endif
}