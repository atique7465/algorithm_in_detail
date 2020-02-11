# algorithm_in_detail
>**<p align="justify">In mathematics and computer science, an algorithm is a finite sequence of well-defined, computer-implementable instructions, typically to solve a class of problems or to perform a computation<p/>**

**Characteristics of an Algorithm:**
- **Unambiguous:** Algorithm should be clear and unambiguous. Each of its steps (or phases), and their inputs/outputs should be clear and    must lead to only one meaning.
- **Input:** An algorithm should have 0 or more well-defined inputs.
- **Output:** An algorithm should have 1 or more well-defined outputs, and should match the desired output.
- **Definiteness** 
- **Finiteness:** Algorithms must terminate after a finite number of steps.
- **effectiveness**
- **Feasibility:**  Should be feasible with the available resources.
- **Independent:**  An algorithm should have step-by-step directions, which should be independent of any programming code.

**Table of common time complexities:**
[https://en.wikipedia.org/wiki/Time_complexity](url)

**Asymptotic Notations**
- **Big O Notation:** defines an upper bound of an algorithm.
- **Ω Notation:** provides an asymptotic lower bound.
- **Θ Notation:** The theta notation bounds a functions from above and below / average bound.

**Optimization problem:** Problems those requires minimum or maximum result.
- the solutions those satisfies the constraint of any problem are the feasible solutions.
- there ore only one solution to any optimization problem. 

**Strategies for solving Optimization problems:**
- Greedy methode
- Dynamic Programming 
- Branch and Bound

------------------------------------------------------------------------------------------------------------------------------------------
# Greedy Method
>**<p align="justify">A greedy algorithm is any algorithm that follows the problem-solving heuristic of making the locally optimal choice at each stage, with the intent of finding a global optimum. In many problems, a greedy strategy does not usually produce an optimal solution, but nonetheless a greedy heuristic may yield locally optimal solutions that approximate a globally optimal solution in a reasonable amount of time.<p/>**

# Dynamic Programming
>**<p align="justify">Dynamic Programming is mainly an optimization over plain recursion. Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming.<p/>**

- **What does a “state” stand for?**<br>
  It’s a way to describe a situation, a sub-solution for the problem.
- **If a problem has tree characteristics below can be solved using DP:**<br>
  •	Subproblems<br>
  •	Overlapping Subproblems<br>
  •	Optimal Substructure : if a problem can be solved optimally by breaking it into sub-problems and then recursively finding the     optimal solutions to the sub-problems, then it is said to have optimal substructure.<br> if sub-problems can be nested recursively    inside larger problems, so that dynamic programming methods are applicable, then there is a   relation between the value of the larger problem and the values of the sub-problems.[1] In the optimization literature this     relationship is called the Bellman equation.<br>

- **Difference between Greedy method and Dynamic Programming:**<br>
    Greed algorithm: Greedy algorithm is one which finds the feasible solution at every stage with the hope of finding global optimum    solution.<br>
   Dynamic Programming: Dynamic programming is one which breaks up the problem into series of overlapping sub-problems.<br>
   Difference are listed below:<br>
   1.	Greedy algorithm is one which finds feasible solution at every stage with the hope of finding optimal solution whereas Dynamic   programming is one which break the problems into series of overlapping sub-problems.
   2.	Greedy algorithm never reconsiders its choices whereas Dynamic programming may consider the previous state.
   3.	Greedy algorithm is less efficient whereas Dynamic programming is more efficient.
   4.	Greedy algorithm has a local choice of the sub-problems whereas Dynamic programming would solve the all sub-problems and then select one that would lead to an optimal solution.
   5.	Greedy algorithm take decision in one time whereas Dynamic programming take decision at every stage.
   6.	Greedy algorithm work based on choice property whereas Dynamic programming work based on principle of optimality.
   7.	Greedy algorithm follows the top-down strategy whereas Dynamic programming follows the bottom-up strategy.

**source:**
01. [https://en.wikipedia.org/wiki/Time_complexity](url)
https://www.quora.com/Whats-the-difference-between-greedy-algorithm-and-dynamic-programming-Is-a-greedy-program-a-subset-of-dynamic-programming
02. http://www.shafaetsplanet.com/?p=1022

# Backtracking
>**<p align="justify">Backtracking is an algorithmic-technique for solving problems recursively by trying to build a solution incrementally, one piece at a time, removing those solutions that fail to satisfy the constraints of the problem at any point of time<p/>**
 - its kinda bruteforce approach used when we may have multiple solutions and we want all of them.
 - a **State space tree** generated and feasible solution will be taken from that tree with some sort of bounding function / condition.
 
 **Diffrence between Backtracking & Branch and Bound:**
 - Backtracking use DFS approach to test and find solutions.
 - Branch and Bound use BFS for test and find the solutions.
 - Branch and Bound are used for minimizasion problem only.
 
 # P, NP, NP-complete, NP-Hard
 The video tutorial below explains everything very well:
 01. [https://www.youtube.com/watch?v=e2cF8a5aAhE&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=72](url)
