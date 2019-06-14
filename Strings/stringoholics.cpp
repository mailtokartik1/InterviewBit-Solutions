// Currently, time limit exceeded!!!I will try again!

long long int mod = 1000000007;
string s2;

// Helper function to calculate the gcd

long long int lcm (int a, int b) {
    long long int temp = ((a % mod) * (b % mod));
    return (int)(temp / (float)__gcd(a, b)) % mod;
}

// Helper function to return rotated string

string rotate (string s, int k) {
    k = k % s.size();
    s2.clear();
    for (int i = k; i < s.size(); i ++) {
        s2 += s[i];
    }
    for (int i = 0; i < k; i ++) {
        s2 += s[i];
    }
    return s2;
}

// Helper function to calculate the minimum count for rotation

long long minCount (string s) {
    int turns = 0;
    long long count = 1;
    s2.clear();
    while (1) {
        string s3 = rotate(s, (int)(count * (count + 1))/(float)2);
        if (s3 == s) {
            return count;
        } else {
            count ++;
        }
    }
    return count;
    
}
int Solution::solve(vector<string> &A) {
    vector<long long> B;
    for (int i = 0; i < A.size(); i ++) {
        B.push_back(minCount(A[i]));
    }

    // Corner case

    if (A.size() == 1) {
        return B[0];
    }
    int len = B.size();
    vector<long long> v = B;
    long long ans=1;
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len && v[i]!=1 ;j++){
            
            v[j] = v[j]/__gcd(v[j],v[i]);
        }
        ans = 1ll*(ans%mod*(v[i])%mod)%mod;
    }
    return ans%mod;
    long long lcm1 = B[0];

    // Calculate the LCM of all the values

    for (int i = 1; i < B.size(); i ++) {
        lcm1 = lcm(lcm1 % mod, B[i] % mod) % mod;
    }
    return lcm1 % mod;
}
