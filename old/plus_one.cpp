#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (0 == digits.size())
        {
            return digits;
        }
        int carry = 1;
        for(auto i = digits.end() - 1; i!=digits.begin()-1 ; i--)
        {
            (*i) += carry ;
            if (*i > 9 )
            {
                carry = *i - 9 ;
                (*i) -= 9 ;
                if (i == digits.begin())
                {
                    digits.insert(digits.begin(),carry);
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return digits;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> digits = stringToIntegerVector(line);
        
        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (0 == digits.size())
        {
            return digits;
        }
        int carry = 1;
        for(auto i = digits.end() - 1; i!=digits.begin()-1 ; i--)
        {
            (*i) += carry ;
            if (*i > 9 )
            {
                carry = *i - 9 ;
                (*i) -= 9 ;
                if (i == digits.begin())
                {
                    digits.insert(digits.begin(),carry);
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return digits;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> digits = stringToIntegerVector(line);
        
        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (0 == digits.size())
        {
            return digits;
        }
        int carry = 1;
        for(auto i = digits.end() - 1; i!=digits.begin()-1 ; i--)
        {
            (*i) += carry ;
            if (*i > 9 )
            {
                carry = *i - 9 ;
                (*i) -= 9 ;
                if (i == digits.begin())
                {
                    digits.insert(digits.begin(),carry);
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return digits;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> digits = stringToIntegerVector(line);
        
        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (0 == digits.size())
        {
            return digits;
        }
        int carry = 1;
        for(auto i = digits.end() - 1; i!=digits.begin()-1 ; i--)
        {
            (*i) += carry ;
            if (*i > 9 )
            {
                carry = *i - 9 ;
                (*i) -= 9 ;
                if (i == digits.begin())
                {
                    digits.insert(digits.begin(),carry);
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return digits;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> digits = stringToIntegerVector(line);
        
        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (0 == digits.size())
        {
            return digits;
        }
        int carry = 1;
        for(auto i = digits.end() - 1; i!=digits.begin()-1 ; i--)
        {
            (*i) += carry ;
            if (*i > 9 )
            {
                carry = *i - 9 ;
                (*i) -= 9 ;
                if (i == digits.begin())
                {
                    digits.insert(digits.begin(),carry);
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return digits;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> digits = stringToIntegerVector(line);
        
        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (0 == digits.size())
        {
            return digits;
        }
        int carry = 1;
        for(auto i = digits.end() - 1; i!=digits.begin()-1 ; i--)
        {
            (*i) += carry ;
            if (*i > 9 )
            {
                carry = *i - 9 ;
                (*i) -= 9 ;
                if (i == digits.begin())
                {
                    digits.insert(digits.begin(),carry);
                    break;
                }
            }
            else
            {
                break;
            }
        }
        return digits;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> digits = stringToIntegerVector(line);
        
        vector<int> ret = Solution().plusOne(digits);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}