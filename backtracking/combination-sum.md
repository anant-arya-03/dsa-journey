# Combination Sum

Find all combinations that add up to the target. We can use each number more than once.

For candidates = [2, 3, 6, 7] and target = 7, the answers are [2, 2, 3] and [7].

## My code

```cpp
class Solution {
public:
    void find(vector<int>& candidates,
              vector<vector<int>>& ans,
              vector<int> temp,
              int sum, int target, int index) {

        if (index == candidates.size()) {
            if (sum == target) {
                ans.push_back(temp);
            }
            return;
        }

        if (sum > target) {
            return;
        }

        find(candidates, ans, temp, sum, target, index + 1);

        sum += candidates[index];
        temp.push_back(candidates[index]);

        find(candidates, ans, temp, sum, target, index);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        find(candidates, ans, temp, 0, target, 0);

        return ans;
    }
};
```

This is the LeetCode-style solution; the platform supplies the vector headers and test runner.

## The simple idea: skip or take

At each number, we explore two choices:

- **Skip it:** move to index + 1. The sum and current combination stay the same.
- **Take it:** add the number to sum and temp, then use the same index again. This lets us pick that number more than once.

| Variable | Meaning |
|---|---|
| temp | The combination we are building |
| sum | Total of the numbers in temp |
| index | The candidate we are considering |
| ans | All valid combinations found |

## When do we stop?

When index reaches candidates.size(), there are no numbers left to consider. If sum equals target, save temp in ans. Otherwise, return without saving.

When sum is greater than target, stop that branch. All candidates are positive, so adding more cannot reduce the total.

## How [2, 2, 3] is formed

| Choice | temp | sum |
|---|---|---|
| Take 2 | [2] | 2 |
| Take 2 again | [2, 2] | 4 |
| Skip 2 and move to 3 | [2, 2] | 4 |
| Take 3 | [2, 2, 3] | 7 |
| Skip the remaining candidates | [2, 2, 3] | 7 |
| Reach the end | Save [2, 2, 3] | 7 |

This shows one successful path. The code explores the skip branch first, so it finds [7] before [2, 2, 3] in this example. The order of the answers does not matter.

## Why is there no pop_back()?

temp is passed by value, so each call gets its own copy. A child call cannot change its parent's vector. sum is also passed by value.

Copying temp makes this version easy to follow, but adds copying overhead. If temp were passed by reference, we would need to undo each push with pop_back().

## What I want to remember

Skip means index + 1. Take again means the same index.

The standard problem assumes positive, distinct candidates. Zero could cause endless recursion in the take branch, and duplicate candidates could produce repeated answers.
