class Solution:
    # @param A : list of integers
    # @return a list of integers
    def maxset(self, A):
        maxlen, maxsum, maxstart = -1, -1, -1
        curlen, cursum, curstart = 0, 0, 0
        for i in range(len(A)):
            if A[i] >= 0:
                cursum += A[i]
                curlen += 1
                if cursum > maxsum:
                    maxsum = cursum
                    maxstart = curstart
                    maxlen = curlen
                elif cursum == maxsum:
                    if curlen > maxlen:
                        maxlen = curlen
                        maxstart = curstart
            else:
                cursum = 0
                curstart = i + 1
                curlen = 0
        return A[maxstart:maxstart + maxlen]