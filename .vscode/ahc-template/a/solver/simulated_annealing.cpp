#pragma once
#include "greedy.cpp"
#include "../template.cpp"

class SimulatedAnnealing
{
public:
  SimulatedAnnealing(Greedy &greedy_)
  {
    this->greedy = greedy_;
    this->greedy.solve_all();
    this->solved_state = this->greedy.get_solved_state();
  }

  State simulate()
  {
    double TIME_LIMIT = 1.9;
#ifdef _GLIBCXX_DEBUG
    TIME_LIMIT = 4.0;
    int max_files = 10;
    int interval = 1;
#endif
#ifndef ONLINE_JUDGE
#ifndef _GLIBCXX_DEBUG
    TIME_LIMIT = 4.0;
#endif
    int count_loop = 0;
    int count_accepted = 0;
    cerr << "score before SA:" << this->solved_state.calc_score() << endl;
    cerr << "state before SA:" << this->solved_state << endl;
#endif
    double start_temp = 50, end_temp = 10;
    State now_state = this->solved_state;
    int now_score = now_state.calc_score();
    int best_score = now_score;
    while (true)
    {
      if (!timer.is_under(TIME_LIMIT))
        break;

      State new_state = this->solved_state;
      modify(new_state);
      int new_score = new_state.calc_score();
      int diff = new_score - now_score;
      double temp = start_temp + (end_temp - start_temp) * (timer.count()) / TIME_LIMIT;
      double prob = exp((diff) / temp);
#ifndef ONLINE_JUDGE
      count_loop++;
#endif
#ifdef _GLIBCXX_DEBUG
      if (count_loop <= interval * max_files && count_loop % interval == 0)
      {
        string filename = "sa/output";
        filename += to_string(count_loop / interval);
        filename += ".txt";
        ofstream ofs(filename);
        ofs << this->solved_state;
      }
#endif
      if (prob > rand_SA.RandomDouble(0, 1))
      {
        swap(now_state, new_state);
        now_score = new_score;
        if (new_score > best_score)
        {
          best_score = new_score;
          this->solved_state = now_state;
        }
#ifndef ONLINE_JUDGE
        count_accepted++;
#endif
      }
    }
#ifndef ONLINE_JUDGE
    cerr << "l/a" << " " << count_loop << " " << count_accepted << endl;
    if (count_accepted != 0)
      cerr << "accept rate" << " " << double(count_accepted) / (double)count_loop << endl;
    else
      cerr << "accept rate" << " " << 0.0 << endl;
    cerr << "score after SA:" << now_state.calc_score() << endl;
    cerr << "state after SA:" << now_state << endl;
#endif
    return this->solved_state;
  }

private:
  Greedy greedy;
  State solved_state;
  Random rand_SA;
  void modify(State &state)
  {
    assert(false && "SimulatedAnnealing::modify() not implemented!");
  }
};