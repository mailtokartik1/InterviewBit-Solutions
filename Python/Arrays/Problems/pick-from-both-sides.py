class Solution:
    # @param A : list of integers
    # @param B : integer
    # @return an integer
    def solve(self, A, B):
        cursum = sum(A[:B])
        j = len(A) - 1
        maxsum = cursum
        for i in range(B - 1, -1, -1):
            cursum += A[j] - A[i]
            maxsum = max(maxsum, cursum)
            j -= 1
        return maxsum