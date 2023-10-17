#pragma once
#include <ctime>

class random {
  public:
    static long long rand();
  private:
    static long long s1;
    static long long s2;
    static long long s3;
};