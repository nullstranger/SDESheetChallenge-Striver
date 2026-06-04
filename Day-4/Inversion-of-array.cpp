// optimal - approach 
# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        long long cnt = 0;
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            // right is smaller
            else {
                temp.push_back(arr[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
        return cnt;
    }
    
    long long mergeSortHelper(vector<int> &arr, int low, int high){
        long long cnt = 0;
        if (low >= high)
            return cnt;
        
        int mid = (low + high) / 2;
        cnt += mergeSortHelper(arr, low, mid);
        cnt += mergeSortHelper(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);
        return cnt;
    }  

    long long int numberOfInversions(vector<int> nums) {
        long long int n = nums.size();
        return mergeSortHelper(nums, 0, n-1);
    }
};