#include <cassert>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
 public:
  /* not working for negative number */
  int removeDuplicates_aux(vector<int>& nums) {
    int len = nums.size();
    // find the max in vector
    int max = *std::max_element(nums.begin(), nums.end());

    // auxiliary array
    vector<int> newArr(max + 1, 0);
    for (int i = 0; i < len; i++) {
      int num = nums[i];
      if (newArr[num] == 0) {
        newArr[num] = 1;
      } else {
        nums.erase(nums.begin() + i);
        i--;
        len--;
      }
    }
    return nums.size();
  }

  int removeDuplicates(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    int slow{0}, fast{0};
    while (fast < nums.size()) {
      if (nums[slow] != nums[fast]) {
        slow++;
        nums[slow] = nums[fast];
      }
      fast++;
    }
    return slow + 1;
  }

  int removeElement(vector<int>& nums, int val) {
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        slow++;
      }
      fast++;
    }
    return slow;
  }

  void moveZeroes(vector<int>& nums) {
    if (nums.size() == 0) return;
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != 0) {
        nums[slow] = nums[fast];
        slow++;
      }
    }
  }
};

int main() {
  Solution solution;
  // vector<int> nums{-1, 0, 0, 0, 0, 3, 3};
  // vector<int> expectedNums{-1, 0, 3};
  // int k = solution.removeDuplicates(nums);
  // assert(k == expectedNums.size());
  // for (int i = 0; i < k; i++) {
  //   std::cout << nums[i] << std::endl;
  //   assert(nums[i] == expectedNums[i]);
  // }

  vector<int> nums{0, 1, 2, 2, 3, 0, 4, 2};
  solution.removeElement(nums, 2);
  for (int i : nums) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}