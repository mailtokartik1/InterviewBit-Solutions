string Solution::convertToTitle(int A) {
    int initial = A;
    string B;
    char c;

    // convert 1 - 26 range to 0 - 25 range by subtracting 1 from the number

    while (A >= 1) {
        if (A % 26 == 0) {
            c = ((A - 1) % 26) + 65;
        } else {
            c = ((A - 1) % 26) + 65;
        }
        B += c;
        A = (A - 1)/ 26;
    }
    reverse(B.begin(), B.end());
    return B;
}
