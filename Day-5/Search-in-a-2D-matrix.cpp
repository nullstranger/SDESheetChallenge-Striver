# include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>> &mat, int target){
        if(!mat.size()) return false;
        int n = mat.size();
        int m = mat[0].size();
        int low = 0;
        int high = (n * m)-1;
        while(low <= high){
            int mid = (low + (high - low)/2);
            if(mat[mid/m][mid%m] == target){
                return true;
            }
            if(mat[mid/m][mid%m] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;
        
    }
};