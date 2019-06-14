bool isPrime(int num) {
    if (num <= 1) {
        return 0;
    } else if (num == 2 || num == 3) {
        return 1;
    } else {
        for (int i = 2; i <= (int)sqrt(num) ; i ++) {
            if (num % i == 0) {
                return 0;
            }
        }
        return 1;
    }
}
vector<int> Solution::sieve(int A) {

    // Alternate solution

    /*
    vector<int> B;
    for (int i = 2; i <= A; i ++) {
        if (i == 2 || i == 3) {
            B.push_back(i);
        } else {
            int j = 2;
            for (j = 2; j <= (int)sqrt(i); j ++) {
                if (i % j == 0) {
                    break;
                }
            }
            if (j == (int)sqrt(i) + 1) {
                B.push_back(i);
            }
        }
    }
    return B;
    */

    // Sieve of Eratosthenes

    vector<int> B(A + 1, 1);
    vector<int> C;
    B[0] = 0;
    B[1] = 0;
    for (int i = 2; i <= A; i ++) {
         if (B[i]) {
             int j = i * 2;
             while (j <= A) {
                 B[j] = 0;
                 j += i;
             }
         }
    }
    for (int i = 0; i < B.size(); i ++) {
        if (B[i] == 1) {
            C.push_back(i);
        }
    }
    return C;
}
