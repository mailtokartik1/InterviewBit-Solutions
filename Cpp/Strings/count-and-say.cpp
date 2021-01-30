// Helper function to get the new string value from the old one

string answer(string s) {
    if (s.length() == 1 && s[0] == '1') {
        return to_string(11);
    }
    int count = 1;
    string p;
    int i;
    bool flag = false;

    // Loop through the array and count the instances of a number to append it in the next turn

    for (i = 0; i < s.length() - 1; i ++) {
        if (s[i + 1] == s[i]) {
            count ++;
            flag = true;
        } else {
            p += (to_string(count));
            p += (s[i]);
            flag = false;
            count = 1;
        }
    }
    if (flag) {
        p += (to_string(count));
        p += (s[s.length() - 1]);
    } else {
        p += (to_string(1));
        p += (s[s.length() - 1]);
    }
    return p;
}

string Solution::countAndSay(int A) {

    // Corner case

    if (A == 1) {
        return to_string(1);
    }
    string s = to_string(1);  

    // Consistently generate new state strings from the previous state

    while (A > 1) {
        s = answer(s);
        A --;
    }
    return s;
}
