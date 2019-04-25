#ifndef __CALC_HPP__
#define __CALC_HPP__

#include <vector>
#include <string>

namespace ic {

std::string calcAddition(std::vector<std::string>& argValue);

std::string calcSubtraction(std::vector<std::string>& argValue);

std::string calcMultiplication(std::string argValue1, std::string argValue2);

std::string calcDivision(std::string argValue1, std::string argValue2);

}

#endif // __CALC_HPP__
