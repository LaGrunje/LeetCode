#include <string>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (s.length() == 1 || numRows == 1) {
            return s;
        }
        
        std::string res;

        for(int i = 0; i < numRows; ++i) {
            int pos = i;
            while (pos < s.length()) {
                res += s[pos];
                if (i == 0 || i == numRows -1)
                {
                    pos += 2 * numRows - 2;
                }
                else{
                    pos += 2 * (numRows - i) - 2;
                    if (pos < s.length()) {
                        res += s[pos];
                    }
                    pos += 2 * i;
                }
            }
        }
        return res;
    }
};