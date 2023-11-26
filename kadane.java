class Solution{

    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
        


    static long maxSubarraySum(int[] arr, int N) {
        long maxEndingHere = arr[0];
        long maxSoFar = arr[0];

        for (int i = 1; i < N; i++) {
            // Choose between extending the current subarray or starting a new subarr
            maxEndingHere = Math.max(arr[i], maxEndingHere + arr[i]);

            // Update the max subarr sum
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }

    
}
