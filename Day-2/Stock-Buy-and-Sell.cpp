# include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int stockBuySell(vector<int> arr, int n){
        int mini = arr [0];
        int maxprofit = 0;
        for(int i = 0; i < n; i++){
            int cost = arr[i] - mini ;
            maxprofit = max(maxprofit, cost);
            mini = min(mini, arr[i]);
        }
        return maxprofit;
        
    }
};

