#include <string>
#include <map>

//Bad code. Need to use constant reference

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::map<char, int> dict;
        int max_length = 0;
        int current_length = 0;
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (dict.find(s[i]) == dict.end()) {
                dict.insert(std::make_pair(s[i], i));
                ++current_length;
            }
            else {
                if (dict[s[i]] >= start) {
                    max_length = std::max(max_length, current_length);
                    current_length = i - dict[s[i]];
                    start = dict[s[i]] + 1;
                }
                else {
                    ++current_length;
                }
                dict[s[i]] = i;

            }
        }
        max_length = std::max(max_length, current_length);

        return max_length;
    }
};
