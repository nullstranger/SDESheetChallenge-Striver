// Given two integers r and c, return the value at the rth row and cth column (1-indexed) in a Pascal's Triangle.
class Solution {
public:
    int pascalTriangleI(int r, int c) {
        return NcR(r-1,c-1);   
    }
    int NcR(int n, int r){
        int resultant = 1;
        for (int i = 0; i < r; i++){
        resultant = resultant * (n-i);
        resultant = resultant/(i+1);
        }
        return resultant;
    }
   
};

// Given an integer numRows, return the first numRows of Pascal's triangle.
# include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int NcR(int n, int r) {
        long long resultant = 1; 
        for (int i = 0; i < r; i++) {
            resultant = resultant * (n - i);
            resultant = resultant / (i + 1);
        }
        return (int)resultant;
    }

    vector<vector<int>> generate(int numRows) {
       vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            
            for (int j = 0; j <= i; j++) {
                row.push_back(NcR(i, j));
            }
            
            triangle.push_back(row);
        }

        return triangle;
    }
};