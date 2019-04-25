#include "util.hpp"
#include "calc.hpp"

namespace ic {

std::string calcAddition(std::vector<std::string>& argValue)
{
    std::vector<std::vector<int>> value;
    for (const std::string v : argValue) {
        value.push_back(str2vec(rstring(v)));
    }
    std::vector<int> anser;
    int moveUp = 0;
    for (int i=0;; ++i) {
        bool isFix = true;
        int add = moveUp;
        for (std::vector<int> v : value) {
            if (i < v.size()) {
                add += v[i];
                isFix = false;
            }
        }
        if (isFix && (add <= 0)) {
            break;
        } else {
            moveUp = add / 10;
            anser.push_back((add % 10));
        }
    }
    return rstring(vec2str(anser));
}

std::string calcSubtraction(std::vector<std::string>& argValue) {
    std::string x;
    return x;
}

std::string calcMultiplication(std::string value1, std::string value2) {
    std::string x;
    return x;
}

std::string calcDivision(std::string value1, std::string value2) {
    std::string x;
    return x;
}

}
