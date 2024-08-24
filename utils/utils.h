#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
class Utils {

public:
    static void parseMatrix(const string& input, vector<vector<double>>& coefficients, vector<double>& d);
    static bool isNumber(const string& str);
    static bool validateMatrixInput(const string& input);
};
#endif // UTILS_H
