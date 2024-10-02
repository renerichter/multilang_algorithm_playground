# Challenges

## Algorithms

### **Dynamic Programming Challenges**

#### A101. Beginner: **Fibonacci Sequence with Memoization**
**Problem:**
Write a function to calculate the nth Fibonacci number. Use memoization to optimize the calculation.
  
**Input:**
- An integer `n` (0 ≤ n ≤ 30).

**Output:**
- The nth Fibonacci number.

**Hints:**
- Fibonacci numbers follow the rule: `F(n) = F(n-1) + F(n-2)`, with `F(0) = 0` and `F(1) = 1`.
- Avoid recalculating Fibonacci numbers by storing intermediate results.

**Solutions**
[Python](../Python/A101-memoizedFibonacci.py), [TypeScript](../TypeScript/A101-memoizedFibonacci.ts), [Cpp](../Cpp/A101-memoizedFibonacci.cpp)
---

#### A102. Advanced: **Longest Increasing Subsequence**
**Problem:**
Given an unsorted array of integers, find the length of the longest increasing subsequence.

**Input:**
- An array of integers `nums` (0 ≤ len(nums) ≤ 2500, -10^4 ≤ nums[i] ≤ 10^4).

**Output:**
- The length of the longest increasing subsequence.

**Hints:**
- Use dynamic programming to track the longest increasing subsequences at each index.
- A time complexity of O(n^2) is acceptable for this challenge.

---

#### A103. Expert: **Knapsack Problem**
**Problem:**
Given `n` items, each with a weight and value, and a knapsack with a maximum capacity `W`, find the maximum value you can carry in the knapsack.

**Input:**
- An integer `n` (1 ≤ n ≤ 200), an integer `W` (1 ≤ W ≤ 10^4), and two lists `weights` and `values` of length `n`.

**Output:**
- The maximum value you can achieve.

**Hints:**
- Use dynamic programming with a 2D array where `dp[i][w]` represents the maximum value for `i` items and a knapsack of capacity `w`.

---

### **Concurrency and Multi-Threading Challenges**

#### A201. Beginner: **Print Numbers Sequentially with Threads**
**Problem:**
Create three threads, each of which prints a specific range of numbers:  
- Thread 1: Print numbers 1-5  
- Thread 2: Print numbers 6-10  
- Thread 3: Print numbers 11-15

Ensure that the numbers are printed in sequential order across the threads.

**Hints:**
- Use thread synchronization (e.g., mutexes, locks, or semaphores) to coordinate the sequence.

---

#### A202. Advanced: **Producer-Consumer Problem**
**Problem:**
Implement a Producer-Consumer pattern using threads and a shared buffer. The producer generates numbers (1 to 100), and the consumer consumes them. Ensure that:
- The producer should not add numbers when the buffer is full.
- The consumer should not consume from an empty buffer.

**Hints:**
- Use a thread-safe queue and appropriate synchronization mechanisms (e.g., condition variables or semaphores).

---

#### A203. Expert: **Dining Philosophers Problem**
**Problem:**
Implement a solution to the Dining Philosophers Problem using 5 threads (representing philosophers). Each philosopher alternates between thinking and eating. They need to pick up two forks (shared resources) to eat, but only one philosopher can hold a fork at a time.

Ensure there is no deadlock or starvation.

**Hints:**
- Use mutexes or semaphores for synchronization.
- Consider deadlock prevention by introducing an order for philosophers to pick up forks.

---

### **Graph Algorithms Challenges**

#### A301. Beginner: **Find if Path Exists in Graph**
**Problem:**
Given a directed graph represented as an adjacency list and two nodes `start` and `end`, write a function to determine if a path exists from `start` to `end`.

**Input:**
- `n`: Number of nodes (2 ≤ n ≤ 100), and an adjacency list of directed edges.

**Output:**
- Return `True` if a path exists, `False` otherwise.

**Hints:**
- Use Depth-First Search (DFS) or Breadth-First Search (BFS) to explore the graph.

---

#### A302. Advanced: **Shortest Path in a Weighted Graph (Dijkstra's Algorithm)**
**Problem:**
Given a weighted, undirected graph with `n` nodes and `m` edges, find the shortest path from a source node `s` to all other nodes.

**Input:**
- `n`: Number of nodes (2 ≤ n ≤ 1000).
- `edges`: A list of tuples `(u, v, w)` where `u` and `v` are nodes and `w` is the weight of the edge.

**Output:**
- A list where the `i-th` element is the shortest path from `s` to node `i`.

**Hints:**
- Implement Dijkstra’s algorithm using a priority queue for optimal performance (O((n + m) log n)).

---

#### A303. Expert: **Strongly Connected Components (Kosaraju's Algorithm)**
**Problem:**
Given a directed graph with `n` nodes and `m` edges, find all the strongly connected components (SCCs) in the graph.

**Input:**
- `n`: Number of nodes (1 ≤ n ≤ 10^5).
- `edges`: A list of directed edges.

**Output:**
- A list of lists, where each inner list contains the nodes in one SCC.

**Hints:**
- Use Kosaraju’s algorithm or Tarjan’s algorithm to find SCCs in O(n + m) time.

---

Here are 10 coding katas related to **number crunching**, **matrix/vector multiplications**, **fitting**, and **optimization** using **Python with PyTorch** and **NumPy**. These challenges are designed to be solvable within 15 minutes.

---

### **Number Crunching & Matrix/Vector Multiplications (5 Challenges)**

#### C101. Beginner: **Matrix Multiplication**
**Problem:**
Write a function that takes two 2D NumPy arrays `A` and `B` and returns their matrix product.

**Input:**
- Two NumPy arrays `A` (shape: `m x n`) and `B` (shape: `n x p`).

**Output:**
- The matrix product of `A` and `B`.

**Hints:**
- Use `numpy.dot()` or `@` for matrix multiplication.

---

#### C102. Beginner: **Element-wise Matrix Operations**
**Problem:**
Given two NumPy matrices `A` and `B`, return the element-wise sum, difference, and product of the two matrices.

**Input:**
- Two matrices `A` and `B` (both with shape `m x n`).

**Output:**
- Element-wise sum, difference, and product of `A` and `B`.

**Hints:**
- Use NumPy’s broadcasting and operations like `+`, `-`, `*`.

---

#### C103. Advanced: **Batch Matrix Multiplication in PyTorch**
**Problem:**
Implement batch matrix multiplication using PyTorch. Given two tensors `A` and `B` with shapes `(batch_size, m, n)` and `(batch_size, n, p)`, return their batch matrix product.

**Input:**
- PyTorch tensors `A` and `B` with shape `(batch_size, m, n)` and `(batch_size, n, p)`.

**Output:**
- A tensor of shape `(batch_size, m, p)` representing the matrix product for each batch.

**Hints:**
- Use `torch.bmm()` for batched matrix multiplication.

---

#### C104. Advanced: **Vectorized Matrix Determinant with NumPy**
**Problem:**
Write a function that computes the determinant of a given square NumPy matrix `A`.

**Input:**
- A square matrix `A` of shape `(n, n)`.

**Output:**
- The determinant of matrix `A`.

**Hints:**
- Use `numpy.linalg.det()` to calculate the determinant.

---

#### C105. Expert: **Eigenvalues and Eigenvectors**
**Problem:**
Given a square matrix `A` using NumPy, compute its eigenvalues and eigenvectors.

**Input:**
- A square matrix `A` of shape `(n, n)`.

**Output:**
- A tuple containing the eigenvalues and the corresponding eigenvectors of matrix `A`.

**Hints:**
- Use `numpy.linalg.eig()` for eigenvalue and eigenvector computation.

---

### **Fitting Challenges (3 Challenges)**

#### C106. Beginner: **Linear Regression with NumPy**
**Problem:**
Implement a simple linear regression using NumPy. Given `X` (a vector of features) and `y` (target values), compute the parameters of the line `y = mx + b` using the least squares method.

**Input:**
- A NumPy array `X` (shape `(n,)`).
- A NumPy array `y` (shape `(n,)`).

**Output:**
- A tuple `(m, b)` representing the slope and intercept of the best-fit line.

**Hints:**
- Use the normal equation: `theta = (X^T * X)^(-1) * X^T * y`.

---

#### C107. Advanced: **Polynomial Curve Fitting with PyTorch**
**Problem:**
Fit a polynomial curve to a given set of data points using PyTorch. The input is `X` and `y`, and you need to fit a polynomial of degree `d`.

**Input:**
- `X`: A PyTorch tensor of shape `(n,)` representing the input data.
- `y`: A PyTorch tensor of shape `(n,)` representing the target data.
- `d`: An integer representing the degree of the polynomial.

**Output:**
- A PyTorch tensor representing the polynomial coefficients.

**Hints:**
- Construct a design matrix for the polynomial features.
- Use `torch.linalg.lstsq()` to solve for the coefficients.

---

#### C108. Expert: **Non-Linear Least Squares Fitting with PyTorch**
**Problem:**
Fit a non-linear function (e.g., a Gaussian) to data using gradient-based optimization in PyTorch. The function to fit is `y = a * exp(-b * (x - c)^2)`.

**Input:**
- `X`: A PyTorch tensor of shape `(n,)` representing the input data.
- `y`: A PyTorch tensor of shape `(n,)` representing the target data.

**Output:**
- The optimized parameters `a`, `b`, and `c`.

**Hints:**
- Define the function in PyTorch, set initial parameters, and use `torch.optim.Adam()` for optimization.

---

### **Optimization Challenges (2 Challenges)**

#### C109. Advanced: **Gradient Descent for Linear Regression**
**Problem:**
Implement gradient descent to minimize the cost function of linear regression. Given `X` (a matrix of features) and `y` (target values), find the parameters that minimize the cost function.

**Input:**
- `X`: A NumPy array of shape `(n, m)` representing the features.
- `y`: A NumPy array of shape `(n,)` representing the target values.

**Output:**
- A NumPy array representing the optimized parameters.

**Hints:**
- Use mean squared error as the loss function.
- Update parameters using the gradient of the loss.

---

#### C110. Expert: **Constrained Optimization with L-BFGS in PyTorch**
**Problem:**
Use the L-BFGS optimizer in PyTorch to minimize a given loss function subject to constraints. The function is `f(x, y) = x^2 + y^2`, and the constraint is `x + y = 1`.

**Input:**
- Initialize `x` and `y` as PyTorch tensors.
  
**Output:**
- The optimized values of `x` and `y` that minimize the function while satisfying the constraint.

**Hints:**
- Use `torch.optim.LBFGS()` for optimization.
- Implement the constraint using Lagrange multipliers or a projection approach.