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
```
### 2. Palindrome Number

### Problem statement: Given an integer `x`, return true if `x` is a palindrome, and false otherwise.

#### Examples:
- **Example 1:** Input x = 121
                 Output: true
                 Explanation: 121 reads as 121 from left to right and from right to left.

- **Example 2:** Input = -121
                 Output: false
                 Explanation: From left to right, it reads -121. From right to left, it becomes 
                              121-. Therefore it is not a palindrome.

- **Example 3:** Input = 10
                 Output: false
                 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

### Solution
- **[Code Solution](https://github.com/Faiaz98/LeetCodeSolves/blob/main/palindrome_number.cpp)**

#### Solution Explanation
The provided solution checks if the given integer is a palindrome by reversing the number and comparing it with the original number.
Here's a step-by-step explanation of the solution:
1. Check if `x` is negative. If so, return `false`.
2. Initialize `reversed` and `temp` as long long integers with `reversed = 0` and `temp = x`.
3. Use a `while` loop to reverse the number `temp`:
  - Get the last digit of `temp` using modulo `% 10`.
  - Multiply `reversed` by 10 and add the last digit.
  - Update `temp` by dividing it by 10.
4. Compare the reversed number `reversed` with the original number `x`.
5. Return `true` if they are equal, indicating `x` is a palindrome. Otherwise, return `false`.

#### Code Solution Explanation
```
Start: Check if x is negative
│
└─> If x < 0, Return false
│
└─> Initialize reversed = 0, temp = x
│
└─> Reverse the number 'temp' using a while loop
    └─> While temp != 0
        │
        └─> Get the last digit of 'temp': digit = temp % 10
        │
        └─> Update 'reversed': reversed = reversed * 10 + digit
        │
        └─> Update 'temp': temp = temp / 10
    │
    └─> End of loop
│
└─> Compare reversed with original x
    └─> If reversed equals x, Return true (x is a palindrome)
    └─> Else, Return false (x is not a palindrome)
```
