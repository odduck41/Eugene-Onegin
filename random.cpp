#include "random.h"


long long random::s1 = static_cast<long long>(std::time(0));
long long random::s2 = static_cast<long long>(std::time(0))/41;
long long random::s3 = 41;
 
long long random::rand() {
    long long nval = (45346573745 * s3 + 5463467567 * s2 + 4575676 * s1) % 5670;
    s1 = s2;
    s2 = s3;
    s3 = nval;
    return nval;
}