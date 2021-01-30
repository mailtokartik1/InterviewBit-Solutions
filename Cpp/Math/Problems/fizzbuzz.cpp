vector<string> Solution::fizzBuzz(int A) {
    vector<string> B(A);

    // check if (i + 1) is divisible by 3 or 5

    for (int i = 0; i < B.size(); i ++) {
        if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0) {
            B[i] = "FizzBuzz";
            continue;
        } else if ((i + 1) % 3 == 0) {
            B[i] = "Fizz";
            continue;
        } else if ((i + 1) % 5 == 0) {
            B[i] = "Buzz";
            continue;
        } else {
            B[i] = to_string(i + 1);
            continue;
        }
    }
    return B;
}
