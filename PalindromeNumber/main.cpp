#include <string>

using namespace std;

class Solution {
public:
    static bool isPalindrome(int x) 
    {
        string num = to_string(x);

        auto start = num.begin();
        auto end = num.end() - 1;

        while (end > start)
        {            
            if (*start != *end)
                return false;

            ++start;
            --end;
        }

        return true;
    }
};

int main()
{
    return Solution::isPalindrome(121);
}