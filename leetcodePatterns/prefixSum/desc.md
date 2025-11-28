# ⭐ Prefix Sum

1. What (definition + intuition)
Definition:
Prefix sum array pre[i] = arr[0] + ... + arr[i].
Used to answer range-sum or cumulative queries in O(1).
Intuition:
Do all accumulation once upfront, reuse it later.
Convert repeated “sum from L to R” from recomputing → simple subtraction.

2. When to Use (trigger signs)
Look for problems involving:
Many range sum queries
“How many X between L and R?”
Answers of form f(r) − f(l−1)
Need cumulative info (count, sum, freq)
Subarray sums, prefix differences
O(N·Q) brute force → too slow → need O(N + Q)

3. Steps / Template
Build prefix array:
pre[0] = arr[0]
for i in 1..n-1:
    pre[i] = pre[i-1] + arr[i]

Query range sum (l to r):
if l == 0:
    return pre[r]
else:
    return pre[r] - pre[l-1]

General template idea:
Precompute cumulative info.
Answer each query with a subtraction.

4. Example Problems
Example 1: Range Sum Queries
Given arr and queries (l, r), return sum in each range.
→ Use prefix sum to answer each in O(1).
Example 2: Number of subarrays with sum = k
Use prefix-sum + hashmap to check if
pre[i] - k existed before.

5. Variations
Difference Array → For fast range updates, then prefix-sum to rebuild final array.
2D Prefix Sum → For matrix area queries.
Prefix XOR → Same idea, using XOR.
Prefix Min/Max → Rare, but used to track cumulative extrema.

6. Mistakes to Avoid
Forgetting the l = 0 special case.
Off-by-one errors building prefix array.
Mixing 1-indexed + 0-indexed formulas.
Applying prefix sums when updates are frequent (Fenwick/Segment Tree may be better).
Using int instead of long long when sums may overflow.

7. Edge Cases
Empty ranges
Negative numbers
Very large values (potential overflow)
Single-element queries (l == r)
l = 0 case → don’t subtract pre[-1]

8. Time Complexity
Build prefix: O(N)
Each query: O(1)
Total: O(N + Q)
