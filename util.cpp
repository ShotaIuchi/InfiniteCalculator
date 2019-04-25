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
