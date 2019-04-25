#include <iostream>
#include <vector>
#include <string>

#include "util.hpp"
#include "calc.hpp"

int main(int argc, char**argv) {
    std::cout << *argv << std::endl;

    std::vector<std::string> srcs;
    std::string src;
    for (int i=1; i<argc; ++i) {
        //std::cout << (argv[i]) << std::endl;
        src = std::string(argv[i]);
        srcs.push_back(src);
    }

    // std::cout << rstring(src) << std::endl;
    // std::vector<int> iii = str2vec(src);
    // std::cout << iii[0] << std::endl;
    // std::cout << iii[1] << std::endl;

    std::vector<std::string> ssrc;
    ssrc.push_back(src);
    ssrc.push_back(src);
    std::string rrr = ic::calcMultiplication(srcs[0], srcs[1]);
    std::cout << rrr << std::endl;
    return 0;
}
