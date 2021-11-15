//
// PalindromeFinder.hpp
//
// Creation - 11/06/2021
// Revision - 11/09/21
//    isPalindrome() is changed to a public member function
//    checkPalindrome() is changed to a private member function.
// Revision - 11/11/21
//    Added the missing first argument to printResult() function:
//    printReault (string str, string result)
// 4.2-3: Addes const to processString() function. 
//

#ifndef PalindromeFinder_hpp
#define PalindromeFinder_hpp

#include "Deque.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include "stdlib.h"
#include <algorithm>
#include <stdio.h>

using namespace std;

class PalindromeFinder
{
public:
    
    // default constructor
    PalindromeFinder() {};
    
    // default destructor
    ~PalindromeFinder() {};
    
    /**
     it checks all the words (excluding the numbers, punctuations and spaces)
     contained in a given phrase/sentence string are unique.
     If any duplicated words are found regardless of the letter case, it will return false.
     @param str - input string to check whether it is a palindrome
     @return true if the input string is a palindrome, false otherwise
     */
    bool allUnique(string str) const;
    
    /**
     It removes all white spaces, numbers, puncutations included in the given string
     and then change all letters to the lower case so the string is ready to be checked
     for palindrome
     @param str - an input string to do pre-process for preparing for the palindrome check
     @return a string which is all lower case, with no numbers, pucuations and white spaces included
     */
    string processString(string str) const;

    /**
     it calls checkPalindromRec( ) method to decide whether a given string is palindrome or not.
     @param str - an input string to check if it is a palindrome
     @return true if the input string is a palindrom, false otherwise
     */
    bool isPalindrome(string str) const;
    
    /**
     It decides whether a given string is a palindrome using iteration approach.
     This method should use Deque data structure to save and handle the given string
     for processing the palindrome check.
     @param str - is a given input string to check whether it is a palindrome or not
     @return true if the given string is found as a palindrome, false otherwise
     */
    bool checkPalindrome(string str) const;
    
    /** It prints out the palindrome checking result on terminal whether a given input string
     is a palindrome or not palindrome, or any non-unique word(s) is (are) included in the given string.
     @param str - a given input string
     @param result - whether the input string is a palindrome or not,  or it has any non-unique word(s)
     @return an entire output string that is printed out to terminal
     */
    string printResult (string str, string result) const;
    
private:
    
    /**
     it decides whether a given string from start position to the end position is palindrome
     using recursive approach, and send the result to the calling function isPalindrome( )
     @param start - the start position of the given string
     @param end - the end position of the given string
     @return true if the given string is found as a palindrome, false otherwise
     */
    bool checkPalindromeRec (string str, int start, int end) const;
    
};

#endif /* PalindromeFinder_hpp */
