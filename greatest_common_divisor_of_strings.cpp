#include <iostream>
#include <vector>
#include <string>
using namespace std;

// условие задачи https://leetcode.com/problems/greatest-common-divisor-of-strings/description/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        
        if (s1.size() < s2.size()) {
            std::swap(s1, s2);
        }

        std::cout << s1.size() << " " << s2.size() << std::endl;

        string divisor = s2;
        
        while(true) {
            
            std::string::iterator jt;

            auto it = s1.begin();

            while(it != s1.end()) {

                jt = divisor.begin();
                while(jt != divisor.end() && it != s1.end()) {
                    if (*it != *jt) {
                        return "";
                    }
                    ++jt;
                    ++it;
                }
            }
            
            if (jt != divisor.end()) {
                divisor = divisor.substr(std::distance(divisor.begin(), jt), 
                                         std::distance(jt, divisor.end()));
                continue;
            }

            auto ct = s2.begin();
            while(ct != s2.end()) {

                jt = divisor.begin();
                while(jt != divisor.end() && ct != s2.end()) {
                    if (*ct != *jt) {
                        return "";
                    }
                    ++jt;
                    ++ct;
                }
            }

            if (jt != divisor.end()) {
                divisor = divisor.substr(std::distance(divisor.begin(), jt), 
                                         std::distance(jt, divisor.end()));
            } else {      
                break;
            }
        }


    




        return divisor;

        
    }
};

int main() {



    return 0;
}