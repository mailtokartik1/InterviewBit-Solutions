struct Trie {
    bool exist;
    int count;
    Trie* next[26];
    Trie(bool val = false) {
        exist = val;
        for (int i = 0; i < 26; i ++) {
            next[i] = NULL;
        }
        count = 0;
    }
};
void add(Trie* A, string s) {
    if (s.size() == 0) {
        return;
    }
    for (int i = 0; i < s.size(); i ++) {
        if (!A -> next[s[i] - 'a']) {
            A -> next[s[i] - 'a'] = new Trie();
        }
        A -> count ++;
        A = A -> next[s[i] - 'a'];
    }
    A -> exist = true;
    return;
}
bool search(Trie* A, string s) {
    if (A == NULL) {
        return 0;
    }
    for (int i = 0; i < s.size(); i ++) {
        if (!A -> next[s[i] - 'a']) {
            return 0;
        } else {
            A = A -> next[s[i] - 'a'];
        }
    }
    if (A -> exist) {
        return 1;
    }
    return 0;
}
int lup(Trie* A, string s) {
    if (s.size() == 0) {
        return 0;
    }
    if (A == NULL) {
        return s.size();
    }
    int count = 1;
    for (int i = 0; i < s.size(); i ++) {
        if (A -> next[s[i] - 'a'] -> count == 1) {
            return count;
        } else {
            count ++;
        }
        A = A -> next[s[i] - 'a'];
    }
    return count;
}
vector<string> Solution::prefix(vector<string> &A) {
    vector<string> B;
    if (A.size() <= 0) {
        return B;
    }
    Trie* trie = new Trie();
    for (int i = 0; i < A.size(); i ++) {
        add(trie, A[i]);
    }
    for (int i = 0; i < A.size(); i ++) {
        if (lup(trie, A[i]) >= A[i].size()) {
            B.push_back(A[i]);
        } else {
            B.push_back(A[i].substr(0, lup(trie, A[i])));
        }
    }
    B = B;
    return B;
}

