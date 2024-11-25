//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while (tc-- > 0) {
            String[] inputLine = br.readLine().split(" ");
            int n = inputLine.length;
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(inputLine[i]);
            }
            System.out.println(new Solution().maxProduct(arr));
        }
    }
}

// } Driver Code Ends


class Solution {
    // Function to find maximum product subarray
    int maxProduct(int[] arr) {
        // code here
        int n = arr.length;
        int curr = 1, max = Integer.MIN_VALUE;
        for(int i = 0; i < n; i++) {
            curr *= arr[i];
            max = Math.max(curr, max);
            if(curr == 0) curr = 1;
        }
        curr = 1;
        for(int i = n - 1; i >= 0; i--) {
            curr *= arr[i];
            max = Math.max(curr, max);
            if(curr == 0) curr = 1;
        }
        return max;
    }
}