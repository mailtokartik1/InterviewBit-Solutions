int Solution::repeatedNumber(const vector<int> &arr) {
    int slow = arr[0]; 
    int fast = arr[0];

    // Flloyd's cycle finding algorithm

    do 
    {
        slow = arr[slow]; 
        fast = arr[arr[fast]]; 
    } while (slow != fast);
  
    // Find the entrance to the cycle
    int ptr1 = arr[0]; 
    int ptr2 = slow; 
    while (ptr1 != ptr2)  
    { 
        ptr1 = arr[ptr1]; 
        ptr2 = arr[ptr2]; 
    } 
  
    return ptr1; 
}
