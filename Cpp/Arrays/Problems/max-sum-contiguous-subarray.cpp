int Solution::maxSubArray(const vector<int> &A) {

    // Apply Kadane's algorithm

    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < A.size(); i++) 
    { 
        max_ending_here = max_ending_here + A[i];

        // If max, set to maximum
        
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
}
