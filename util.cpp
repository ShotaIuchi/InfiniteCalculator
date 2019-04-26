#include <algorithm>
#include "util.hpp"

std::string rstring(const std::string& src)
{
    std::string dst(src);
    std::reverse(dst.begin(), dst.end());
    return dst;
}

std::vector<int> str2vec(const std::string& src)
{
    std::vector<int> dst;
    std::for_each(src.cbegin(), src.cend(), [&](char c) {
            dst.push_back((c - '0'));
        });
    return dst;
}

std::string vec2str(const std::vector<int>& src)
{
    std::string dst;
    for (int v : src) {
        dst.append(std::to_string(v));
    }
    return dst;
}

bool largeLeft(const std::vector<int>& value1, const std::vector<int>& value2)
{
    if (value1.size() > value2.size()) {
        return true;
    }
    if (value1.size() < value2.size()) {
        return false;
    }
    for (int i=0; i<value1.size(); ++i) {
        if (value1[i] > value2[i]) {
            return true;
        }
        if (value1[i] < value2[i]) {
            return false;
        }
    }
    return true;
}
