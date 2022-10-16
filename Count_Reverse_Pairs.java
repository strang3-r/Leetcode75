//https://leetcode.com/problems/reverse-pairs/
//Given an array of numbers, you need to return the count of reverse pairs. Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j].
//    Time Complexity : O( N log N ) + O (N) + O (N)
//    Space Complexity : O(N)

import java.util.*;

public class Count_Reverse_Pairs {
    static int merge(int[] nums, int low, int mid, int high) {
        int cnt = 0;
        int j = mid + 1;
        for(int i = low;i<=mid;i++) {
            while(j<=high && nums[i] > (2 * (long) nums[j])) {
                j++;
            }
            cnt += (j - (mid+1));
        }

        ArrayList<Integer> temp = new ArrayList<>();
        int left = low, right = mid+1;
        while(left <= mid && right<=high) {
            if(nums[left]<=nums[right]) {
                temp.add(nums[left++]);
            }
            else {
                temp.add(nums[right++]);
            }
        }

        while(left<=mid) {
            temp.add(nums[left++]);
        }
        while(right<=high) {
            temp.add(nums[right++]);
        }

        for(int i = low; i<=high;i++) {
            nums[i] = temp.get(i - low);
        }
        return cnt;
    }
    static int mergeSort(int[] nums, int low, int high) {
        if(low>=high) return 0;
        int mid = (low + high) / 2;
        int inv = mergeSort(nums, low, mid);
        inv += mergeSort(nums, mid+1, high);
        inv += merge(nums, low, mid, high);
        return inv;
    }
    public int reversePairs(int[] nums) {
        return mergeSort(nums, 0, nums.length - 1);
    }
}


