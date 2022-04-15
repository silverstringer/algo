//Task: Two Sum
//Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//You can return the answer in any order.



#include <iostream>
#include <vector>
using std::vector;


class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {

        auto a = 0;
        for(auto i = nums.begin(); i != nums.end(); i++)
        {
            auto b = a + 1;
            for (auto j = nums.begin() + b; j != nums.end(); j++) {
                if (target == (*i + *j)) {
                    return {a,b};
                }
                b++;
            }
            a++;
        }
        return {};
    }
};


int main () {

    vector<int> test_vec {1, 2, 7, 11, 15};
    auto target = 9;

    Solution sol;
    auto result = sol.twoSum(test_vec, target);

    for(auto value: result)
        std::cout <<"Index: " <<value <<"\n";


  return 0;
}