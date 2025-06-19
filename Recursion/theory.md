# 📘Theory of Recursion (From Basic to Advanced)

---

## 📌 What is Recursion?

Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.

A function that calls itself directly or indirectly is known as a recursive function.

---

## ✅ Key Rules of Recursion

1. **Base Case**: The condition under which the function stops calling itself.
2. **Recursive Case**: The part where the function calls itself with a modified input.
3. **Progress towards Base Case**: Ensure each recursive call brings the input closer to the base case.

---

## 🧠 How to Think Recursively

* Break the problem into smaller sub-problems.
* Solve one sub-problem and trust recursion to solve the rest (faith step).
* Use recursion tree or stack trace to visualize calls.

---

## 📦 Recursion vs Iteration

| Feature          | Recursion                      | Iteration                    |
| ---------------- | ------------------------------ | ---------------------------- |
| State Memory     | Uses call stack                | Uses loop control            |
| Code Readability | Often shorter/clearer          | Sometimes more efficient     |
| Speed            | Slower (due to stack overhead) | Faster (low-level control)   |
| Risk             | Stack overflow if too deep     | Infinite loop if not handled |

---

## 🔨 Types of Recursion

1. **Tail Recursion**: Recursive call is the last operation.
2. **Head Recursion**: Recursive call is before any processing.
3. **Tree Recursion**: Function makes multiple recursive calls.
4. **Indirect Recursion**: Function A calls B, B calls A.
5. **Nested Recursion**: Recursive call's parameter is another recursive call.

---

## 🔄 Recursion Tree & Stack Space

* Each call adds a frame to the call stack.
* Depth of recursion = height of recursion tree.
* Helps visualize overlapping calls.

---

## 🔍 Recursion Time Complexity

Use recursion tree or recurrence relation:

* `T(n) = T(n-1) + O(1)` → O(n)
* `T(n) = 2T(n/2) + O(n)` → O(n log n) (Merge Sort)
* `T(n) = T(n-1) + T(n-2)` → Exponential (Fibonacci)

---

## 🧩 Recursion with Backtracking (CP Problems)

Common in:

* N-Queens
* Sudoku Solver
* Combinatorics (Subset, Permutations)

Pattern:

```cpp
void solve(state) {
    if (base case) {
        store/print result;
        return;
    }
    for (choices) {
        make a choice;
        solve(next state);
        undo choice (backtrack);
    }
}
```

---

## 🧠 Memoization + Recursion (Top-Down DP)

Avoids recomputation using a cache (e.g. map/array):

```cpp
unordered_map<int, int> dp;
int fib(int n) {
    if (n <= 1) return n;
    if (dp.count(n)) return dp[n];
    return dp[n] = fib(n-1) + fib(n-2);
}
```

---

## 🔁 Convert Recursion to Iteration (Advanced Skill)

Use an explicit stack to simulate recursion:

* Helps reduce stack overflow
* Used in DFS, Traversals

---

## 🏆 Master Patterns in CP

### 1. **Subsets / Powersets**

```cpp
void subset(vector<int>& nums, int i, vector<int>& curr) {
    if (i == nums.size()) {
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[i]);
    subset(nums, i+1, curr);
    curr.pop_back();
    subset(nums, i+1, curr);
}
```

### 2. **Permutations**

```cpp
void permute(vector<int>& nums, int idx) {
    if (idx == nums.size()) {
        ans.push_back(nums);
        return;
    }
    for (int i = idx; i < nums.size(); ++i) {
        swap(nums[i], nums[idx]);
        permute(nums, idx+1);
        swap(nums[i], nums[idx]);
    }
}
```

### 3. **DFS on Graph/Grid**

```cpp
void dfs(int node) {
    visited[node] = true;
    for (int nei : graph[node]) {
        if (!visited[nei]) dfs(nei);
    }
}
```

---

## 📚 Practice Problems (from Easy to CP Level)

### 🟢 Easy

* Factorial
* Fibonacci
* Sum of digits
* Reverse a string/array using recursion

### 🟡 Medium

* Generate Subsets
* Permutations
* Palindrome Partitioning
* Combination Sum

### 🔴 Hard / CP Level

* N-Queens
* Sudoku Solver
* Word Break
* Expression Add Operators
* Knight’s Tour
* Backtracking on Graph (Hamiltonian Path, Coloring)

---

## 🚩 Common Mistakes

* Forgetting base case
* Infinite recursion
* Not restoring state (in backtracking)
* Not memoizing overlapping subproblems

---

## 🧠 Final Tips

* Dry run every recursive function on paper.
* Master recursion tree for complexity.
* Learn to memoize where needed.
* Don’t brute force unless backtracking is clearly the optimal path.

---

## 🔥 Resources to Go Deeper

* Leetcode Recursion Tag
* Neetcode Backtracking Playlist
* Competitive Programming 3 (Steven Halim)
* CP Handbook (by Errichto)
* DP + Recursion: Aditya Verma Playlist

---

**Start with recursion. Master backtracking. Climb to DP. Conquer CP.**
