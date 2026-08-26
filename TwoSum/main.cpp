#include <vector>
#include <cstddef>
#include <iostream>
#include <unordered_map>

std::vector<std::int32_t> nums = { 2, 7, 11, 15 };
std::int32_t target = 9;

std::unordered_map<std::int32_t, std::size_t> map;

int main()
{
    for (auto i = 0u; i < nums.size(); ++i)
    {
        if (map.find(target - nums[i]) == map.end())
        {
            map[nums[i]] = i;
        }
        else
        {
            std::cout << i << "\n" << map[target - nums[i]];
            return 0;
        }
    }

    return -1;
}