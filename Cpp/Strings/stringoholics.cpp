#define MOD 1000000007
typedef long long ll;

// Helper function to return progressive sum

ll prod(ll n) {
    return ((n * (n + 1))) / 2;
}

// Function to return the min time taken to get the original string after rotation

ll timeTaken(string s) {
    if (s.size() == 1) {
        return 1;
    }
    while (s.size() % 2 == 0) {
        string firstHalf = string(s.begin(), s.begin() + s.size() / 2);
        string secondHalf = string(s.begin() + s.size() / 2, s.end());
        if (firstHalf == secondHalf) {
            s = firstHalf;
        } else break;
    }
    ll res = 1;
    int i = 1;
    for (; i < 2 * s.size(); i ++) {
        if (prod(i) % s.size() == 0) {
            return i;
        }
    }
    return i; 
}

// Create sieve of erastothenes and map prime numbers

unordered_map<ll, ll> makeSieve(int n = 500) {
    unordered_map<ll, ll> umap;
    vector<bool> num(n, 1);
    for (int i = 2; i * i <= n; i ++) {
        for (int j = 2; j * i <= n; j ++) {
            num[i * j] = 0;
        }
    }
    for (int i = 2; i < num.size(); i ++) {
        if (num[i]) {
            umap[i] = 0;    
        }
    }
    return umap;
}

// Seperate the factors of the min. time to get LCM

void seperateFactors(ll num, unordered_map<ll, ll> &umap) {
    for (auto it: umap) {
        ll exponentVal = 0;
        if (num % it.first == 0) {
            while (num % it.first == 0) {
                exponentVal ++;
                num /= it.first;
            }
            if (exponentVal > it.second) {
                umap[it.first] = exponentVal;    
            }
        }
    }
    if (num != 1) {
        umap[num] = 1;    
    }
    return;
}

// Driver

int Solution::solve(vector<string> &A) {
    ll res = 1;
    auto umap = makeSieve();
    for (int i = 0; i < A.size(); i ++) {
        long long val = timeTaken(A[i]);
        seperateFactors(val, umap);
    }
    for (auto it: umap) {
        ll expVal = 1;
        ll maxExp = it.second;
        while (maxExp) {
            expVal = (expVal * it.first) % MOD;
            maxExp --;
        }
        res = (res * expVal) % MOD;
    }
    return res;
}

// Alternate solution: Below solution exceeds time limit

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
