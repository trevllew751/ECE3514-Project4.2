//
//  PalindromeFinder.cpp
//  

#include <set>
#include <vector>
#include "PalindromeFinder.hpp"

//TO DO


bool PalindromeFinder::allUnique(string str) const {
    std::set<std::string> strings;
    std::string temp;
    for (char c: str) {
        if (isalpha(c)) {
            temp += tolower(c);
        } else if (isspace(c) && !temp.empty()) {
            if (strings.count(temp) && temp.size() > 1) {
                return false;
            }
            strings.insert(temp);
            temp = "";
        }
    }
    if (!temp.empty()) {
        if (strings.count(temp) && temp.size() > 1) {
            return false;
        }
    }
    return true;
//    std::set<std::string> strings;
//    std::string temp;
//    for (char c : str) {
//        if (isspace(c)) {
//            temp = processString(temp);
//            if (strings.count(temp)) {
//                return false;
//            } else {
//                strings.insert(temp);
//            }
//            temp = "";
//        } else {
//            temp += c;
//        }
//    }
//    if (!temp.empty()) {
//        temp = processString(temp);
//        if (strings.count(temp)) {
//            return false;
//        }
//    }
//    return true;
}

string PalindromeFinder::processString(string str) const {
    std::vector<std::string> strings;
    std::string temp;
    std::string result;
    for (char c: str) {
        if (isalpha(c) || isspace(c)) {
            temp += tolower(c);
        } else if (isspace(c) && !temp.empty()) {
            if (std::count(strings.begin(), strings.end(), temp) && temp.size() > 1) {
                return "duplicated";
            }
            strings.push_back(temp);
            temp = "";
        }
    }
    if (!temp.empty()) {
        if (std::count(strings.begin(), strings.end(), temp) && temp.size() > 1) {
            return "duplicated";
        }
        strings.push_back(temp);
    }
    for (std::string &s : strings) {
        result += s;
    }
    return result;
}

bool PalindromeFinder::isPalindrome(string str) const {
    std::string processed = processString(str);
    if (processed.size() == 1 || processed.size() == 0) {
        return true;
    }
    return checkPalindromeRec(processed, 0, processed.size() - 1);
}

bool PalindromeFinder::checkPalindrome(string str) const {
    Deque<char> dq;
    std::string processed = processString(str);
    for (char c : processed) {
        dq.pushBack(c);
    }
    while (!dq.isEmpty()) {
        if (dq.front() != dq.back()) {
            return false;
        }
        dq.popFront();
        if (dq.isEmpty()) {
            break;
        }
        dq.popBack();
    }
    return true;
}

string PalindromeFinder::printResult(string str, string result) const {
    return "\"" + str + "\" " + result;
}

bool PalindromeFinder::checkPalindromeRec(string str, int start, int end) const {
    if (start == end) {
        return true;
    } else if (start == end - 1) {
        return str.at(start) == str.at(end);
    }
    return (str.at(start) == str.at(end)) && checkPalindromeRec(str, start + 1, end - 1);
}
