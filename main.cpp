#include "reader.h"
#include "random.h"

int main() {
    Text a("Source.txt");
    int b[7];
    for (auto& i: b) {
        i = random::rand();
    }
    a.print(b[0]);
    a.print(a.get_rhythm(b[0]));
    a.print(b[1]);
    a.print(a.get_rhythm(b[1]));
    std::cout << std::endl;
    a.print(b[2]);
    a.print(b[3]);
    a.print(a.get_rhythm(b[2]));
    a.print(a.get_rhythm(b[3]));
    std::cout << std::endl;
    a.print(b[4]);
    a.print(b[5]);
    a.print(a.get_rhythm(b[5]));
    a.print(a.get_rhythm(b[4]));
    std::cout << std::endl;
    a.print(b[6]);
    a.print(a.get_rhythm(b[6]));

}