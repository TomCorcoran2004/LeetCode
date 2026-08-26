#include <string>
#include <unordered_map>
#include <array>

using namespace std;

string s = "pwwkew";

class Solution {
public:
    static int lengthOfLongestSubstring(string s)
    {
        int current_substring_start = 0;
        int current_longest_substring = 0;

        array<int, 255> last_seen;
        fill(last_seen.begin(), last_seen.end(), 0);

        for (int i = 0; i < s.length(); ++i)
        {
            if (current_substring_start <= last_seen[s[i]])
            {
                int current_substring_length = i - current_substring_start;
                
                current_longest_substring = max(current_substring_length, current_longest_substring);

                current_substring_start = i;
            }

            last_seen[s[i]] = i;
        }
        
        return current_longest_substring;
    }

};

int main()
{
    return Solution::lengthOfLongestSubstring(s);
}