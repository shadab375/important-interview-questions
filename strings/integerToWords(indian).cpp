//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    
    string ones[20] = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", 
                        "ten ", "eleven " , "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", 
                        "seventeen ", "eighteen ", "nineteen "};
    string tens[10] = {"", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
    
    string numToWord(int n, string suffix) {
        string str = "";
        
        if (n>=20) {
            str += tens[n/10];
            n = n%10;
        }
        if (n>0) {
            str += ones[n];
        }
        if (!str.empty()) str += suffix;
        
        return str;
    }


    string convertToWords(long n) {
        string res = "";
        res += numToWord((n/10000000)%100, "crore ");
        res += numToWord((n/100000)%100, "lakh ");
        res += numToWord((n/1000)%100, "thousand ");
        res += numToWord((n/100)%10, "hundred ");
        
        if (n>100 && n%100) res += "and ";
        res += numToWord((n%100), "");
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long n;
        cin >> n;
        Solution ob;
        auto ans = ob.convertToWords(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends