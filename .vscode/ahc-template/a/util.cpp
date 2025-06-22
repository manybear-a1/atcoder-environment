#pragma once
#include "template.cpp"

// ref:https://qiita.com/sorachandu/items/041169d34b9f9b99bcf7#timer-%E6%99%82%E9%96%93%E8%A8%88%E6%B8%AC%E7%94%A8class
class Timer
{
  chrono::system_clock::time_point start;

public:
  Timer() : start(chrono::system_clock::now()) {}

  double count()
  {
    chrono::duration<double> Time_ = chrono::system_clock::now() - start;
    return Time_.count();
  }

  bool is_under(double x)
  {
    return (this->count()) < x;
  }
};
Timer timer;

// ref :https://atcoder.jp/contests/ahc048/submissions/66624955
class Random
{
public:
  Random() : state_(3141592653589793238ULL) {}

  double RandomDouble(double a, double b)
  {
    Update();
    const double r = state_ * kScale_;
    return a + (b - a) * r;
  }

  int RandomInt(int a, int b)
  {
    return static_cast<int>(RandomDouble(a, b));
  }

  int RandomIntInclusive(int a, int b)
  {
    return RandomInt(a, b + 1);
  }

private:
  uint64_t state_;

  // 2^(-64)
  static constexpr double kScale_ = 1.0 / 18446744073709551616.0;

  void Update()
  {
    // xorshift
    state_ ^= state_ >> 13;
    state_ ^= state_ << 7;
    state_ ^= state_ >> 17;
  }
};

#ifdef _GLIBCXX_DEBUG
class OStreamRedirect
{
  std::ostream &os;
  std::streambuf *old_buf;

public:
  OStreamRedirect(std::ostream &os_, std::ostream &new_stream)
      : os(os_), old_buf(os_.rdbuf(new_stream.rdbuf())) {}
  ~OStreamRedirect()
  {
    os.rdbuf(old_buf);
  }
};
#endif