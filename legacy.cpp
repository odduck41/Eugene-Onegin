#include <fstream>
#include <iostream>
#include <ctime>
#include "random.h"

bool ingnore(char a) {
    char ign[10] = {',', '.', ';', ' ', '-', '"', '!', '?', ')', '\r'};
    for (int i = 0; i < 10; ++i) {
        if (a == ign[i]) {
            return true;
        }
    }
    return false;
}
bool rhythm(std::string a, std::string b) {
    std::string f;
    std::string s;
    for (int i = a.size() - 1; i >= 0; --i) {
        if(!ingnore(a[i])) {
            int t = 0;
            for(int k = i - 3; k <= i; ++k){
                f += a[k];
                ++t;
            }
            break;
        }
    }
    for (int i = b.size() - 1; i >= 0; --i) {
        if(!ingnore(b[i])) {
            int t = 0;
            for(int k = i - 3; k <= i; ++k){
                s += b[k];
                ++t;
            }
            break;
        }
    }
    if (s == f) {
        //std::cout << s << " " << f << std::endl;
        return true;
    } 
    return false;
}
char* get_rhthm(const char* a, char** txt) {
    for (int i = 0; i < 5669; ++i) {
        if (rhythm(a, txt[i]) && a != txt[i]) {
            return txt[i];
        }
    }
    return txt[0];
}

int main() {
    std::ifstream is("Source.txt");
    char* a = new char[150005 * 2];
    is.read(a, 150005 * 2);
    char** splited = new char*[5669];
    int j = -1;
    for (int i = 0; i < 5669; ++i) {
        int k = j + 1;
        while (a[k] != '\n') {
            ++k;
        }
        splited[i] = new char[k - j];
        for (int f = 0; f < k - j; ++f) {
            splited[i][f] = a[f + j + 1];
        }
        splited[i][k - j - 1] = '\0';
        j = k;
    }

    auto f = splited[random::rand()];
    auto s = splited[random::rand()];
    auto th = splited[random::rand()];
    auto fo = splited[random::rand()];
    auto fi = splited[random::rand()];
    auto si = splited[random::rand()];
    auto se = splited[random::rand()];
    std::cout << f << std::endl;
    std::cout << get_rhthm(f, splited) << std::endl;
    std::cout << s << std::endl;
    std::cout << get_rhthm(s, splited) << std::endl;
    std::cout << th << std::endl;
    std::cout << fo << std::endl;
    std::cout << get_rhthm(th, splited) << std::endl;
    std::cout << get_rhthm(fo, splited) << std::endl;
    std::cout << fi << std::endl;
    std::cout << si << std::endl;
    std::cout << get_rhthm(si, splited) << std::endl;
    std::cout << get_rhthm(fi, splited) << std::endl;
    std::cout << se << std::endl;
    std::cout << get_rhthm(se, splited) << std::endl;
}