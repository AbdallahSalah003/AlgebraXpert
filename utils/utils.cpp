#include "utils.h"

void Utils::parseMatrix(const string& input, vector<vector<double>>& coefficients, vector<double>& d) {
    stringstream ss(input);
    string line;
    vector<double> row;

    // Temporary vector to hold values for each row
    vector<double> currentRow;

    while (getline(ss, line)) {
        stringstream lineStream(line);
        currentRow.clear();
        double value;

        // Read values from the line
        while (lineStream >> value) {
            currentRow.push_back(value);
        }

        // Separate last element of the currentRow as part of d
        if (!currentRow.empty()) {
            d.push_back(currentRow.back()); // Last column
            currentRow.pop_back(); // Remove last column from row
        }

        // Add the modified row to coefficients
        coefficients.push_back(currentRow);
    }
}

bool Utils::isNumber(const string& str) {
    if (str.empty()) return false;
    size_t i = 0;
    if (str[0] == '-') i = 1;
    bool hasDecimalPoint = false;
    for (; i < str.size(); ++i) {
        if (str[i] == '.') {
            if (hasDecimalPoint) return false;
            hasDecimalPoint = true;
        } else if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

bool Utils::validateMatrixInput(const string& input) {
    stringstream ss(input);
    string line;
    vector<size_t> rowLengths;
    size_t numCols = 0;
    size_t numRows = 0;

    while (getline(ss, line)) {
        stringstream lineStream(line);
        string value;
        vector<string> valuesInLine;

        while (lineStream >> value) {
            if (!Utils::isNumber(value)) {
                return false;
            }
            valuesInLine.push_back(value);
        }


        if (numCols == 0) {
            numCols = valuesInLine.size();
        } else if (valuesInLine.size() != numCols) {
            return false;
        }

        numRows++;
    }

    if (numRows != numCols - 1) return false;

    return true;
}
