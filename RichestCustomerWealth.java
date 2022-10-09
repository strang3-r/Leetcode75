class Solution {
    public int maximumWealth(int[][] accounts) {
        int m = accounts.length;
		int n = accounts[0].length;
		int arr[] = new int[m];
		int sum = 0;
		for(int i = 0 ; i < m ; i++) {
			for(int j = 0 ; j < n ; j++) {
				sum+=accounts[i][j];
			}
			arr[i] = sum;
			sum=0;
		}
		int max = arr[0];
		for(int i = 0 ; i < m ; i++) {
			if(arr[i]>max) {
				max = arr[i];
			}
		}
		return max;
    }
}
