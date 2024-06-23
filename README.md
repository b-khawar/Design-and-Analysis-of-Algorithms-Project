# Design and Analysis of Algorithms
This project contains solutions to four challenging algorithmic problems, each solved with a focus on optimizing both space and time complexity. The solutions include detailed pseudocode and C++ implementations.<br/><br/>

# Problem Descriptions

## Problem 1: Counting Structures

**Objective:** Determine the number of different structures that can be built from exactly n blocks, where 3 ≤ 𝑛 ≤ 200. Each structure consists of stages with distinct heights, where each stage is lower in height than the previous one.<br/>

**Input:** A positive integer 𝑛.<br/>

**Output:** The number of different structures that can be built.

**Example:**<br/>
For 𝑛 = 5, there are two structures: heights (4, 1) and (3, 2).<br/><br/>

## Problem 2: Minimizing Strategic Value

**Objective:** Determine the smallest Strategic Value for a railroad after performing up to m attacks on the rail line.<br/>

**Input:** Multiple datasets; each dataset starts with two integers n (number of depots) and m (number of attacks), followed by n integers representing the Strategic Value of each depot.<br/>

**Output:** The smallest Strategic Value that can be achieved for the railroad with m attacks.

**Example:**<br/>
**Input:**<br/>
4 1<br/>
4 5 1 2<br/>
4 2<br/>
4 5 1 2<br/>
0 0<br/>
<br/>
**Output:**<br/>
17<br/>
2<br/><br/>

## Problem 3: Segmenting Array

**Objective:** Divide an array A of length n into k segments where k > 1 such that each segment has the same Minimum Not Presented Number (MNPN). If no such division exists, report -1.<br/>

**Input:** An integer N, followed by N integers representing the array A.<br/>

**Output:** Number of segments followed by the range of the segments, or -1 if no valid division exists.

**Example:**<br/>
**Input:**<br/>
5<br/>
1 2 3 4 5<br/>
<br/>
**Output:**<br/>
2<br/>
1 1<br/>
2 5<br/><br/>

## Problem 4: Maximizing Hunter Power

**Objective:** Select hunters from a grid of M rows and N columns to maximize the power level of the team while adhering to the constraints.<br/>

**Input:** Multiple test cases; each test case starts with two integers M (rows) and N (columns), followed by M rows each having N values representing the power levels of the hunters.<br/>

**Output:** Maximum power that can be achieved by the team.<br/>

**Example:**<br/>
**Input:**<br/>
1 10<br/>
1 2 3 4 5 5 4 3 2 1<br/>
2 3<br/>
1 10 35<br/>
10 3 11<br/>
2 5<br/>
11 5 7 9 5<br/>
7 10 3 6 7<br/>
<br/>
**Output:**<br/>
5<br/>
45<br/>
39<br/><br/>

# How to Run
1. Select the question from the PDF having the Problem Statements.<br/>
2. Compile the repective cpp file.<br/>
3. Run the object file.<br/><br/>
