
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    unordered_map<string, string> bucket{
        {"2", "abc"}, {"3", "def"},  {"4", "ghi"}, {"5", "jkl"},
        {"6", "mno"}, {"7", "pqrs"}, {"8", "tuv"}, {"9", "wxyz"}};

public:
    void backtracking(int level, string& digits, vector<string>& res,
                      string& str) {
        if (level == digits.size()) {
            res.push_back(str);
            return;
        }
        string tmp = bucket[string(1, digits[level])];
        for (auto ch : tmp) {
            str.push_back(ch);
            backtracking(level + 1, digits, res, str);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string str = "";
        int level = 0;
        if (digits == "")
            ;
        else {
            backtracking(level, digits, res, str);
        }
        return res;
   }
};

// Function to print the result
void printResult(const vector<string>& result) {
    for (const auto& s : result) {
        cout << s << " ";
    }
    cout << endl;
}

// Test cases
int main() {
    Solution solution;
    
    vector<string> result1 = solution.letterCombinations("23");
    printResult(result1);  // Output: ad ae af bd be bf cd ce cf
    
    vector<string> result2 = solution.letterCombinations("");
    printResult(result2);  // Output: (empty)
    
    vector<string> result3 = solution.letterCombinations("2");
    printResult(result3);  // Output: a b c
    
    vector<string> result4 = solution.letterCombinations("7");
    printResult(result4);  // Output: p q r s

    vector<string> result5 = solution.letterCombinations("79");
    printResult(result5);  // Output: pw px py pz qw qx qy qz rw rx ry rz sw sx sy sz
    
    vector<string> result6 = solution.letterCombinations("5");
    printResult(result6);  // Output: j k l
    return 0;
}
