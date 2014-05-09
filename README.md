Programmathon
=============

###Naming Scheme

>TeamName/ProblemName

###DataSets:
>[2014 competition test cases.](http://lifenoodles.com/stuff/nuim-comp-2014.zip)

Questions
=========

Array Rotations
---------------

Right circular rotation is an array operation which shifts each element one position to the right, with a[n-1] taking the place of a[0]. 

e.g. [1, 2, 3, 4, 5] shifted right 2 times is [4, 5, 1, 2, 3] 

An array A of N integers has been shifted right K times. You will be asked Q queries which consist of a single integer X. You must print the value A[X]. 

###Constraints:
>1 <= N <= 10^5  
>1 <= A[i] <= 10^5  
>1 <= K <= 10^5  
>1 <= Q <= 5000  
>0 <= X <= N-1 

###Input Format:
The first line contains 3 integers, N, K and Q, separated by spaces.
The second line is N integers separated by spaces, which are the elements of A.
These are followed by Q lines of a single integer, X. 

Output Format:
For each query Q, print out the value of A[X] on a new line.

Ananananananagrams
------------------

Given 2 strings A and B you need to determine the minimum total number of letters which need to be removed from both strings to transform them into anagrams of one another. 

e.g.  
A = “hello”  
B = “lol”  
The answer is 2 as deleting the “h” and “e” from “hello” will make it an anagram of “lol”. 

###Constraints:
A and B wil be composed of lowercase latin letters a-z  
1 <= length of A & B <= 10^6 

###Input Format:
2 lines, each containing a single string. 

###Ouput Format:
A single integer which is the number of characters which should be deleted from A and B

Chopping Chocolate
------------------

You have a big chocolate bar of N rows and M columns. All of your no good greedy friends want you to share and so you agree even though you secretly hate them all. Unfortunately, earlier in the day you had left the chocolate bar sitting in the sun and it had melted and then cooled down again. But it was too late, all the chocolate had become warped, leaving the bar with uneven thickness. 

The bar is separated by lines into rows and columns of little squares but due to the melting incident, it takes more effort to break along certain lines than others.

You’re feeling particularly lazy and need to figure out the easiest way to break the bar completely into single squares. 

There are N - 1 horizontal lines and M - 1 vertical lines, and you will be given costs Hi (horizontal) and Vi (vertical) for each line. Breaking a piece of chocolate along a given line will cost C for each distinct piece of chocolate broken. 

e.g. Given a 2 x 3 bar with  
H1 = 4  
V1 = 2  
V2 = 3  
[][][]  
[][][]   

The cheapest way to break the bar is to first break it along the horizontal line H1. This costs 4 to break, and there is 1 piece of chocolate being broken, for a cost of 4 * 1. This leaves 2 separate 1 x 3 bars behind, with all the horizontal lines broken.    
[][][]

[][][] 

Next you should break both remaining pieces along the line V1 for a cost of 2. This time there are 2 pieces of chocolate to break, since you split it in half with the first break on H1. Breaking both of these bars costs 2 * 2 = 4 total. After breaking the 1 x 3 bars, you now have 2 separate 1 x 2 bars and 2 single squares fully broken off.  
[] [][] 

[] [][] 

Finally, you should break the line V2 in the 1 x 2 bars at a cost of 3 for each piece of chocolate, 3 * 2 = 6.  
[] [] [] 

[] [] [] 

The total cost to break the bar into single squares was (H1 * 1) + (V2 * 2) + (V3 * 2) = 14 

###Constraints:  
>1 <= T <= 20  
2 <= N, M <= 10^6  
0 <= Hi <= 10^9  
0 <= Vi <= 10^9   

###Input Format:
There is a single integer T on the first line, T testcases follow.
Each testcase begins with 2 positive integers, N and M, separated by a space.
In the next line there are N - 1 integers H1, H2 … H[n-1] separated by spaces, indicating the cost of a horizontal cut along line Hi.
On the following line there are M – 1 integers V1, V2 … V[m-1] separated by spaces, indicating the cost of a vertical cut along line Vi. 

###Output Format:
The minimum total cost to fully divide the bar.


Zombie Outbreak
---------------
A city is divided into N regions, labelled A - Z. All regions of the city are connected to 0 or more other regions via roads or railway. In this city there has been an outbreak of cliché and zombies are eating everyone. It takes 1 week for the zombies to spread from an infected region to a non-infected region and make it infected, but there are survivors in each region trying to stop the zombies from spreading. In order to infect a region, at least 3 neighbouring regions must be infected for at least a week. In this situation the zombies can overwhelm the survivors. 

Your task is to determine the number of weeks it will take for the entire city to be infected, or if it is impossible for zombies to infect all regions. 

###Constraints:
>3 <= N <= 26  
0 <= K <= 100   

###Input format:
The first line is an integer N, the number of regions in the city.  
The second line is an integer K, the number of connections that exist between regions of the city.    
The third line contains a 3 letter string indicating the initial infected regions.  
This is followed by K lines, each containing a 2 letter string XY indicating a connection between region X and region Y. Regions that are connected are connected both ways, so X is connected to Y and Y is connected to X.   

###Output format:
>Output either the string:  
“Full infection is not possible.”  
Or:  
“Full infection will happen in X weeks.”  
Where X is the number of weeks it will take for all regions of the city to be infected.

Subset Wont Sum
---------------
Subset Sum is a famous problem in computer science where we ask, given a set of integers, is there a non-empty subset whose sum is zero?  

Well, the solution to this problem has nothing to do with it whatsoever. For Subset Won’t Sum, you will be given an array of positive integers S. The question is this: Given a lower bound and an upper bound on the array, can you compute the minimum non-zero positive integer that is NOT the sum of some subset of the numbers within the bounds.   

For example, given the array [2, 1, 9, 4, 10], and the bounds [1, 1] (indexed from 1 and inclusive of high and low), the solution is 1. This is because the minimum positive number that cannot be made from the set {2} is 1. However, given the bounds [1, 4], the answer is 8. This is because the numbers 1 through 7 can be expressed as the sum of 1 or more of the numbers from the set {1, 2, 4, 9}.   

i.e.  
1 = 1  
2 = 2  
3 = 2 + 1  
4 = 4  
5 = 4 + 1  
6 = 4 + 2  
7 = 4 + 2 + 1  
8 = ?   

###Constraints:

1 <= N, M <= 10^5
1 <= Si <= 10^9
1 <= S1 + S2 + S3 + … + Sn <= 10^9 

###Input format:
The first line is an integer N, indicating how many elements there are in the array S. The next line is the N numbers that make up the array S, space separated. The third line is the integer M, the number of questions you will be asked. The remaining M lines are 2 space separated integers, the lower and upper bounds on the query. 

###Output format:
M integers, 1 per line, giving the smallest positive non-zero integer that is NOT the sum of a subset of numbers Sx through Sy inclusive, indexed from 1.  
