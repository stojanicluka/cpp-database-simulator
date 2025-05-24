/* Contains the implementation of the SelectResult methods */

#include "SelectResult.h"

using namespace std;

SelectResult::operator std::string() const {

    // Print a row count message
    string s = "Fetched " + to_string(rows.size()) + " rows:\n";

    // If there are no fetched rows, do nothing more
    if (rows.empty())
        return s;

    // Prepare data for formatting as a table
    vector<vector<string> > tableData;
    tableData.push_back(vector<string>());

    // Prepare header
    unordered_set<string> columns = rows[0].getColumnNames();
    for (auto &column : columns)
        tableData[0].push_back(column);

    // Prepare fetched data
    for (auto r : rows) {
        vector<string> row;
        for (auto &column : columns)
            row.push_back(r.getValue(column));
        tableData.push_back(row);
    }

    return s + printTable(tableData);
}

// Takes a pointer to Record object and adds it to the rows array
void SelectResult::addRow(const Record &r) {
    rows.push_back(r);
}

// Prints given matrix of data in a form of a table and returns a string
string SelectResult::printTable(const vector<vector<string>> &data) const {

    // Table display parameters
    const char tableChar = '=';
    const int cellWidth = 15;

    if (data.empty())
        return "";

    int tableWidth = (cellWidth * data[0].size()) + (data[0].size() + 1); // Table row width (chars)

    // Print all rows
    string s;
    for (auto &v : data) {
        s += string(tableWidth, tableChar) + "\n";

        // Print all row cells
        for (auto &c : v) {

            // Set the string width to the predefined value
            string temp = " " + c;
            int moreBlanks = cellWidth - temp.size();
            if (moreBlanks > 0)
                temp.append(string(moreBlanks, ' '));
            else
                temp = temp.substr(cellWidth);

            // Append one table cell
            s += string(1, tableChar) + temp;
        }

        // Append right border char and go to new line
        s += string(1, tableChar) + "\n";
    }

    // Print the bottom border
    s += string(tableWidth, tableChar) + "\n";

    return s;
}

// Returns a statement result as a vector of pointers to Record objects
const vector<Record> &SelectResult::getResult() const {
    return rows;
}
