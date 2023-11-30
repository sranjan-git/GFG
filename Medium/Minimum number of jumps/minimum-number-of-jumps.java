//{ Driver Code Starts
import java.lang.*;
import java.io.*;
import java.util.*;
class GFG
 {
	public static void main (String[] args) throws IOException
	 {
	 
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int t = Integer.parseInt(br.readLine()); 

        while(t-- > 0){
            int size = Integer.parseInt(br.readLine());
            String[] arrStr = ((String)br.readLine()).split("\\s+");
            int[] arr= new int[size];
            for(int i = 0;i<size;i++){
                arr[i] = Integer.parseInt(arrStr[i]);
            }
            System.out.println(new Solution().minJumps(arr));
        }
	 }
	 
}

// } Driver Code Ends


class Solution{
    static int minJumps(int[] arr){
        int n = arr.length;
        
        // array is empty
        if(n<=1) {
            return 0;
        }
        
        // index can't be reached as no steps or max_reach are available
        if(arr[0] == 0) {
            return -1;
        }
        // your code here
        // max_reach: max reach from 0 index
        // steps: available steps from current index (max_reach - i)
        // jumps: count of jumps
        int max_reach = arr[0], steps = arr[0], jumps = 1;
        
        for(int i = 1; i<n; i++) {
            if(i == n-1) {
                return jumps;
            }
            
            
            // find and update max_reach fron 0 index to current traversed index and it's steps.
            max_reach = Math.max(max_reach, i + arr[i]);
            steps--;
            
            if(steps == 0) {
                jumps++;
                
                // if there is no reach from current index
                if(i >= max_reach) {
                    return -1;
                }
                
                // update steps available from current index 
                steps = max_reach - i;
            }
        }
        return jumps;
    }
}