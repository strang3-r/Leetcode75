class Solution {
    int BinarySearch(int n){
        long s = 0;
        long e =  n ;
        long mid = s + (e-s)/2;
        long ans = -1;
        while(s<=e){
            long sq = mid*mid;

            if(sq==n){
                return (int)mid;
            }

            if(sq < n){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return (int)ans ;
    }
    public int mySqrt(int x) {
        return BinarySearch(x);
    }
}
