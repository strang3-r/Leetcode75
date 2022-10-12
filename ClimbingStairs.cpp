class Solution {
public:
    int climbStairs(int n) {
        int arr[46]; // array for 1 <= n <= 45
        arr[1] = 1; // only one way
        arr[2] = 2; // two ways 1->1 or directly 2
        
        
        // from n = 3 ==> calculate from last two steps
        for(int i = 3; i <= n; i++){
            arr[i] = arr[i-1]+arr[i-2];
        }
        return arr[n];
        
    }
};
