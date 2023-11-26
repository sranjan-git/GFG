class Solution {

    static int missingNumber(int[] arr, int N) {
        int xorResult = 0;

        // XOR all the numbers from 1 to N
        for (int i = 1; i <= N; i++) {
            xorResult ^= i;
        }

        // XOR all the elements in the array
        for (int num : arr) {
            xorResult ^= num;
        }

        return xorResult;
    }

    
}
