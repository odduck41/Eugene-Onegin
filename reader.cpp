#include "reader.h"

Text::Text(const char* filename):txt_(new char[150005 * 2]) {
    lines.resize(5669);
    std::ifstream is(filename);
    is.read(txt_, 150005 * 2);
    int begin = -1;
    int end = begin;
    for (int i = 0; i < 5669; ++i) {
        int count = 0;
        begin = end + 1;
        end = begin;
        for (;txt_[end] != '\n'; ++end);
        lines[i] = {begin, end};
        // std::cout << lines[i].first << " " << lines[i].second << std::endl;
    }
}

std::pair<int, int> Text::operator[](const int ind) const{
    return lines[ind];
}

void Text::print(int a) {
    for (int i = lines[a].first; i <= lines[a].second; ++i) {
        std::cout << txt_[i];
    }
}

const char* Text::get() const {
    return txt_;
}

bool Text::ignore(char a) {
    char ign[11] = {',', '.', ';', ' ', '-', '"', '!', '?', ')', '\r', '\n'};
    for (int i = 0; i < 11; ++i) {
        if (a == ign[i]) {
            return true;
        }
    }
    return false;
}

bool Text::rhythm(std::pair<int, int> f, std::pair<int, int> s) {
    int fu;
    int su;
    for (int i = f.second; i > f.first; --i) {
        if (!ignore(txt_[i])) {
            fu = i;
            break;
        }
    }
    for (int i = s.second; i > s.first; --i) {
        if (!ignore(txt_[i])) {
            su = i;
            break;
        }
    }
    for (int i = 0; i < 4; ++i) {
        if (txt_[su - i] != txt_[fu - i]) {
            return false;
        }
    }
    return true;
}

int Text::get_rhythm(int a) {
    int ans = 0;
    for (;; ++ans) {
        if (rhythm(lines[a], lines[ans]) && ans != a) {
            return ans;
        }
    };
    return ans;
}