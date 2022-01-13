#include <header.h>

class Solution
{
public:
    // vector<int> searchRange(vector<int> nums, int target)
    // {

    //     int l = 0;
    //     int r = nums.size() - 1;
    //     int find_index = -1;
    //     while (l <= r)
    //     {
    //         int index = (l + r) / 2;
    //         if (nums[index] == target)
    //         {
    //             find_index = index;
    //             break;
    //         }
    //         else if (nums[index] > target)
    //         {
    //             r = index - 1;
    //         }
    //         else
    //         {
    //             l = index + 1;
    //         }
    //     }
    //     int res_l = find_index;
    //     int res_r = find_index;

    //     while (res_l - 1 >= 0 && nums[res_l - 1] == target)
    //     {
    //         --res_l;
    //     }
    //     while (res_r + 1 < nums.size() && nums[res_r + 1] == target)
    //     {
    //         ++res_r;
    //     }

    //     return {res_l, res_r};
    // }

    vector<int> searchRange(vector<int> nums, int target)
    {
        int l_index = bin_find(nums, target, true);
        int r_index = bin_find(nums, target, false) - 1;

        if (l_index <= r_index && r_index <= nums.size() && nums[l_index] == target && nums[r_index] == target)
        {
            return {l_index, r_index};
        }

        return {-1, -1};
    }

    int bin_find(vector<int> &nums, int target, bool lower)
    {
        int l = 0;
        int r = nums.size() - 1;
        int find_index = nums.size();
        while (l <= r)
        {
            int index = (l + r) / 2;
            if (nums[index] > target || (lower && nums[index] >= target))
            {
                r = index - 1;
                find_index = index;
            }
            else
            {
                l = index + 1;
            }
        }
        return find_index;
    }
};

int main()
{
    Solution s;
    auto v = s.searchRange({1}, 1);
    return 0;
}