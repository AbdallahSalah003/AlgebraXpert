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
    static void parseMatrix(const string& input, vector<vector<double>>& data);
    static bool isNumber(const string& str);
    static bool validateSystemCoeffiecientsInput(const string& input);
    static bool validateMatrixInput(const string& matrix);
};
#endif // UTILS_H
