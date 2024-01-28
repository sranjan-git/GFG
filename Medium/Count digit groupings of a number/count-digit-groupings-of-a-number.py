#User function Template for python3

class Solution:
	def TotalCount(self, s):
        pfs=[int(x) for x in s]
        for i,v in enumerate(pfs):
            if i-1<0:continue
            pfs[i]+=pfs[i-1]
        m=i+1
        from functools import lru_cache
        @lru_cache(None)
        def dp(cur=0,psm=0):
            nonlocal pfs,m
            if cur==m:
                return 1
            ans=0
            prv=pfs[cur-1] if cur-1>=0 else 0
            for nxt in range(cur,m):
                if psm<=pfs[nxt]-prv:
                    ans+=dp(nxt+1,pfs[nxt]-prv)
            return ans
        ans=dp()
        return ans
#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
	T=int(input())
	for i in range(T):
		s = input()
		ob = Solution()
		ans = ob.TotalCount(s)
		print(ans)
# } Driver Code Ends