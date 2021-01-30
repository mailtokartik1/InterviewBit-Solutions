vector<int> s;
vector<int> A;
MinStack::MinStack() {

    // Clear the environment variables

    s.clear();
    A.clear();
}

void MinStack::push(int x) {

    // Push the minimum value of the vector cooresponding to the indices

    s.push_back(x);
    if (A.size() == 0) {
        A.push_back(x);
    } else {
        A.push_back(min(x, A[A.size() - 1]));
    }
}

void MinStack::pop() {

    // Remove the last element from the arrays

    if (s.size()) {
        s.erase(s.end() - 1);
        A.erase(A.end() - 1);
        return;
    } else return;
}

int MinStack::top() {

    // Return the last element from the original array

    if (s.size()) {
        return s[s.size() - 1];
    } else return -1;
}

int MinStack::getMin() {

    // Return the last element from the min array

    if (!s.size()) {
        return -1;
    } else {
        return A[A.size() - 1];
    }
}

