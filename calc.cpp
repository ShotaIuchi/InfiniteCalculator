#include "util.hpp"
#include "calc.hpp"
#include <iostream>

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

std::string calcSubtraction(std::string argValue1, std::string argValue2) {
    std::vector<int> bvalue1 = str2vec(rstring(argValue1));
    std::vector<int> bvalue2 = str2vec(rstring(argValue2));
    std::vector<int> value1, value2;
    // value1 >= value2
    if (largeLeft(bvalue1, bvalue2)) {
        value1 = bvalue1;
        value2 = bvalue2;
    } else {
        value1 = bvalue2;
        value2 = bvalue1;
    }
    // calc
    std::vector<int> anser;
    int moveDown = 0;
    for (int i=0;; ++i) {
        bool isFix = true;
        int sub = 0;
        if (i < value1.size()) {
            isFix = false;
            sub = value1[i];
            if (i < value2.size()) {
                sub -= value2[i];
            }
            sub -= moveDown;
        }

        if (sub < 0) {
            moveDown = 1;
            sub += 10;
            anser.push_back(sub);
        } else {
            if (isFix) {
                if (sub != 0 || anser.empty()) {
                    anser.push_back(sub);
                }
                break;
            }
            anser.push_back(sub);
        }
    }

    // 頭の0削除
    // 1の位は必要なので削除しない
    for (int i=anser.size()-1; i>=1; --i) {
        if (anser[i] == 0) {
            anser.pop_back();
        } else {
            break;
        }
    }

    if (largeLeft(bvalue1, bvalue2)) {
        return rstring(vec2str(anser));
    } else {
        return "-" + rstring(vec2str(anser));
    }
}

std::string calcMultiplication(std::string argValue1, std::string argValue2) {
    std::vector<int> value1 = str2vec(rstring(argValue1));
    std::vector<int> value2 = str2vec(rstring(argValue2));
    std::vector<std::string> value;
    int c = 0;
    for (int v1 : value1) {
        int moveUp = 0;
        std::vector<int> t;
        // 桁上げ
        for (int i=0; i<c; ++i) {
            t.push_back(0);
        }
        c++;
        // 乗算
        for (int v2 : value2) {
            int a = v1 * v2 + moveUp;
            moveUp = a / 10;
            t.push_back((a % 10));
        }
        // 終わりに繰り上げ値考慮
        // 繰り上げ値の最大は8（9*9の10の位）となるため再度の繰り上げ考慮は不要
        if (0 < moveUp) {
            t.push_back(moveUp);
        }
        value.push_back(rstring(vec2str(t)));
    }
    return calcAddition(value);
}

std::string calcDivision(std::string value1, std::string value2) {
    std::string x;
    return x;
}

}
