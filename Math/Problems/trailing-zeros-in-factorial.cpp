// Number of 5s combine with 2s to make 10

int Solution::trailingZeroes(int A) {
    int tot = 0, i = 1;
    while (floor(A/pow(5, i)) != 0) {
        tot += floor(A/pow(5, i));
        i ++;
    }
    return tot;
}
