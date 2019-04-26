#ifndef __UTIL_HPP__
#define __UTIL_HPP__

#include <string>
#include <vector>

std::string rstring(const std::string& src);
std::vector<int> str2vec(const std::string& src);
std::string vec2str(const std::vector<int>& src);

bool largeLeft(const std::vector<int>& value1, const std::vector<int>& value2);

#endif // __UTIL_HPP__
