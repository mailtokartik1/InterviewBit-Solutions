
int Solution::isPower(int A) {

    // corner case

    if (A == 1) {
        return 1;
    }
    for (int i = 2; i <= sqrt(A); i ++) {
        if (i == sqrt(A)) {
            return 1;
        } else {

            // absolute difference of float can vary hence a random small number is chosen for comparison

            float temp = (float)log(A)/(float)log(i);
            if ((abs(temp) - (int)(temp) < 0.00001) && (int)temp > 1) {
                return 1;
            }
        }
    }
    return 0;
}
