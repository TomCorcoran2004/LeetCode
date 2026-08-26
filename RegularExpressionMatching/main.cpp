using namespace std;

#include <string>
#include <iostream>

class Solution {
public:
    static bool isMatch(string s, string p) 
    {
        auto it_s = s.begin();
        auto it_p = p.begin();

        while (it_s != s.end() && it_p != p.end())
        {
            if (*it_p == '.')
            {
                if (*(it_p + 1) == '*')
                    return true;

                ++it_s;
                ++it_p;
            }

            if (*it_p == '*')
            {
                char val = *it_s;

                while (*it_s == val && it_s != s.end())
                {
                    ++it_s;
                }

                if (it_s == s.end() && it_p + 1 == p.end())
                    return true;

                ++it_p;
            }

            if (*it_s == *it_p)
            {
                ++it_s;
                ++it_p;
            }
            else
            {
                return false;
            }
        }

        if (it_s == s.end() && it_p == p.end())
            return true;
        else return false;
    }
};

int main()
{
    string s = "aa";
    string p = "a";
    
    std::cout << (int)Solution::isMatch(s, p);
}