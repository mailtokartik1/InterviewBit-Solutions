int Solution::largestRectangleArea(vector<int> &A) {
    stack<int> st;
    int sol = 0;
    int i = 0, n = A.size();

    while(i < n){

        // Push the elements on to the stack if it is empty or if the current element is greater than the top element

        if(st.empty() || A[st.top()] <= A[i]){
            st.push(i);
            i++;
        }

        // Else find the area all of the elements in the stack and take its maximum

        else{
            int top = st.top();
            st.pop();
            
            int area = 0;
            
            if(st.empty()){
                area = A[top] * i;
            }
            else{
                area = A[top] * (i - st.top() - 1);
            }

            sol = max(sol, area);
        }
    }

    // Do the same procedure for the end
    
    while(!st.empty()){
        int top = st.top();
        st.pop();
        
        int area = 0;
        
        if(st.empty()){
            area = A[top] * i;
        }
        else{
            area = A[top] * (i - st.top() - 1);
        }
        
        sol = max(sol, area);
    }
    
    return sol;
    
}