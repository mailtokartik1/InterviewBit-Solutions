def maxmin(A):
    if len(A) == 1:
        return A[0], A[0]
    elif len(A) == 2:
        return max(A[0], A[1]), min(A[0], A[1])
    
    maxl, minl = maxmin(A[:int(len(A) / 2)])
    maxr, minr = maxmin(A[int(len(A) / 2):])
    return max(maxl, maxr), min(minl, minr)
class Solution:
    # @param A : list of integers
    # @return an integer
    def solve(self, A):
        return sum(maxmin(A))

# Explanation of complexity:

# T(n) denotes the number of comparisons for input of size number
# T(0) = 0, T(1) = 0, T(2) = 1

# Base equation
# T(n) = 2T(n / 2) + 2

# Derived equation
# T(n) = 2^kT(n / 2^k) + 2^k+1 - 2

# Since T(2) = 1,
# n / 2^k = 2 => k = log(n) - 1 where base(log) = 2

# Replacing the value of k in the derived equation above:
# T(n) = 3n / 2 - 2