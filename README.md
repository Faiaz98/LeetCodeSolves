# LeetCodeSolves

 **This section will explain every question and solution in details**
 The order of the solutions is maintained by following this doc: [LeetCode Problem Solving - Google Sheets](https://docs.google.com/spreadsheets/d/1ALWFKBXCXnUmORkkXgLVTj23veQVlgUS8x_o_JcO-go/edit?usp=sharing)

## 1. Two Sum problem 
   
###problem statement: The task is to find two numbers in an array that add up to a given target.
   The goal is to return the indices of these two numbers.

###Examples:
- **Example 1:** Input: nums = [2,7,11,15], target = 9
             Output: [0,1]
             Explanation: nums[0] + nums[1] == 9, so the indices are [0,1].

- **Example 2:** Input: nums = [3,2,4], target = 6
             Output: [1,2]

- **Example 3:** Input: nums = [3,3], target = 6
             Output: [0,1]

### Solution
- **[Code Solution](https://github.com/Faiaz98/LeetCodeSolves/blob/main/two_sum.cpp)**

#### Solution Explanation
The provided solution uses a hashmap (`unordered_map` in C++) to store the elements of the input array along with their indices.
Here's a step-by-step explanation of the solution:
1. **Initialize a Hash Map:** Create an empty hash map to store the elements and their indices.
2. **Iterate Through the Array:** Loop through the given array `nums`.
3. **Calculate the Complement:** For each element `nums[i]`, calculate the complement `c = target - nums[i]`.
4. **Check if Complement Exists:** If the complement `c` is found in the hash map, return the indices `[numIndex[c], i]`.
5. **Store Element and Index:** If the complement doesn't exist, store the current element `nums[i]` in the hash map with its index `i`.
6. **Return Empty Array as Default:** If no solution is found, return an empty array `{}`.

#### Code Solution Explanation
```plaintext
 nums = [2, 7, 11, 15], target = 9

    Algorithm Steps:

    Start           Initialize an empty hash map (numIndex)
    │                │
    │                ▼
    │          ┌─────────────┐
    │          │ numIndex {} │
    │          └─────────────┘
    │                │
    │     ┌──────────┘
    │     │
    │     │    Iterate through the array 'nums'
    │     │         │
    │     ▼         ▼
    │ ┌───────────────────────────┐
    │ │  For i = 0 to nums.size() │
    │ └───────────────────────────┘
    │           │          │
    │           │          │
    │           ▼          │
    │     ┌─────────────┐  │
    │     │ c = target -│  │
    │     │     nums[i] │  │
    │     └─────────────┘  │
    │           │          │
    │           ▼          │
    │     ┌─────────────┐  │
    │     │ If c exists │  │
    │     │ in numIndex │  │
    │     └─────────────┘  │
    │           │          │
    │           │          │
    │           ▼          │
    │ ┌────────────────────┘
    │ │  Return [numIndex[c], i]
    │ └────────────────────┐
    │           │          │
    │           │          │
    │           ▼          │
    │    ┌──────────────┐  │
    │    │ Store nums[i]│  │
    │    │   in numIndex│  │
    │    └──────────────┘  │
    │           │          │
    │           │          │
    │           ▼          │
    │ ┌───────────────────────────────┐
    │ │  numIndex[nums[i]] = i        │
    │ └───────────────────────────────┘
    │           │          │
    │           ▼          │
    │     ┌──────────────┐ │
    │     │ Continue loop│ │
    │     └──────────────┘ │
    │           │          │
    ▼           ▼          ▼
  Return      ┌───────────────────────────────┐
    {}        │   Return an empty array {}    │
              └───────────────────────────────┘
