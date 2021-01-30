class Solution:
    # @param A : tuple of list of integers
    # @return a list of integers
    def spiralOrder(self, A):
        left = top = 0
        right = len(A[0]) - 1
        bottom = len(A) - 1
        B = []
        while top <= bottom and left <= right:
            for i in range(left, right + 1):
                B.append(A[top][i])
            
            top += 1
            if top <= bottom:
                for i in range(top, bottom + 1):
                    B.append(A[i][right])
            else:
                break
            
            right -= 1
            if left <= right:
                for i in range(right, left - 1, -1):
                    B.append(A[bottom][i])
            else:
                break
            
            bottom -= 1
            if top <= bottom:
                for i in range(bottom, top - 1, -1):
                    B.append(A[i][left])
            else:
                break
            
            left += 1
        return B