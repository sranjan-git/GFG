#User function Template for python3
class Solution:
	def removeDups(self, str):
		# code here
		s=str
		seen = []
        return ''.join([char for char in s if char not in seen and not seen.append(char)])

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        s = input()

        ob = Solution()
        answer = ob.removeDups(s)

        print(answer)

# } Driver Code Ends