// Pascal’s triangle is a pattern of the triangle which is based on nCr.below is the pictorial representation of Pascal’s triangle.

// Example:

// Input : N = 5
// Output:
//           1
//         1   1
//       1   2   1
//     1   3   3   1
//   1   4   6   4   1


 
#include <bits/stdc++.h>
  
using namespace std;
void printPascal(int n)
{
      
for (int line = 1; line <= n; line++)
{
    int C = 1; // used to represent C(line, i)
    for (int i = 1; i <= line; i++) 
    {
          
        // The first value in a line is always 1
        cout<< C<<" "; 
        C = C * (line - i) / i; 
    }
    cout<<"\n";
}
}
  
// Driver code
int main()
{
    int n = 5;
    printPascal(n);
    return 0;
}
