Given a 2D-array of dimension n × n, write a program to find a local maximum element that runs in O(n log n) time. An element A[i][j] in a 2D-array is referred to as local maximum element, if A[i][j] is maximum when compared to the neighbours of A[i][j].

You are given a Matrix A[3][3]
					 	
Here local maximum element is A[1][1] = 25

Note a matrix may have multiple peak elements. We have to just display any one. 

Input Format

The first like contains i and second line contatins j where order of the matrix is i x j.

The third line contatins the values of the matrix.

Constraints

i > 0

j > 0

Output Format

Return any one local maximum element.

Sample Input 0

3 3
13 15 12
2 25 14
4 10 12

Sample Output 0

25

Explanation 0

Neighbours of 25 are 15 14 10 and 2. 