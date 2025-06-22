#pragma once
#include "greedy.cpp"
#include "../template.cpp"

class BeamSearch
{
public:
  BeamSearch(Greedy &greedy_, int beam_width_) : greedy(greedy_), beam_width(beam_width_)
  {
  }

  State search()
  {
    State initial;
    vector<State> current_beam = {initial};

    int max_steps = 100;
    for (int step = 0; step < max_steps; ++step)
    {
      vector<State> next_candidates;
      unordered_set<int> seen_hashes;

      for (const State &state : current_beam)
      {
        for (int seed = 0; seed < 5; ++seed)
        {
          State next = state;
          greedy.solve_partial(next, seed);
          if (seen_hashes.count(next.hash))
            continue;
          seen_hashes.insert(next.hash);
          next_candidates.push_back(next);
        }
      }

      if (next_candidates.empty())
        assert(false && "next_candidates is empty");

      partial_sort(next_candidates.begin(), next_candidates.begin() + min(beam_width, (int)next_candidates.size()), next_candidates.end(), greater<>());

      if ((int)next_candidates.size() > beam_width)
        next_candidates.resize(beam_width);

      current_beam = next_candidates;
    }

    return *max_element(current_beam.begin(), current_beam.end(), [](const State &a, const State &b)
                        { return a.calc_score() < b.calc_score(); });
  }

private:
  Greedy greedy;
  int beam_width;
};