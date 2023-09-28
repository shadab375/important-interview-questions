#include <bits/stdc++.h>
using namespace std;

class Solution {
public:


    vector<string> ones = {"", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", 
                      "Ten ", "Eleven " , "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", 
                      "Seventeen ", "Eighteen ", "Nineteen "};
    vector<string> tens = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

    string numToWord(int n, string suffix) {
        string str  = "";

        if (n >= 100) {
            str += ones[n/100] + "Hundred ";
            n = n%100;
        }
        if (n >= 20) {
            str += tens[n/10];
            n = n%10;
        }
        if (n > 0) str += ones[n];
        if (!str.empty()) str += suffix;
        
        return str;
    }

    string numberToWords(int n) {
        if (n == 0) return "Zero";

        string res = "";
        res += numToWord((n/1000000000)%1000, "Billion ");
        res += numToWord((n/1000000)%1000, "Million ");
        res += numToWord((n/1000)%1000, "Thousand ");
        res += numToWord(n%1000, "");

        while (res.back() == ' ') res.pop_back();

        return res;
    }
};