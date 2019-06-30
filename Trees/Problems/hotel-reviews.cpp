struct Trie {
    bool exist;
    Trie* next[26];
    Trie(bool val = false) {
        exist = val;
        for (int i = 0; i < 26; i ++) {
            next[i] = NULL;
        }
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
int returnMaxIndex(vector<int> &A, unordered_map<int, int> &map) {
    int maxi = INT_MIN;
    int index = -1;
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] > maxi && map[i] != 1) {
            maxi = A[i];
            index = i;
        }
    }
    map[index] = 1;
    return index;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    Trie* root = new Trie();
    unordered_map<string, int> map;
    unordered_map<int, int> map2;
    string temp;
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == '_') {
            add(root, temp);
            temp.clear();
        } else {
            temp += A[i];
        }
        i ++;
        if (i == A.size()) {
            add(root, temp);
            temp.clear();
        }
        i --;
    }
    vector<int> scores(B.size()), res;
    temp = "";
    for (int i = 0; i < B.size(); i ++) {
        int score = 0;
        for (int j = 0; j < B[i].size(); j ++) {
            if (B[i][j] == '_') {
                if (search(root, temp) == 1) {
                    score ++;       
                }
                temp.clear();
            } else {
                temp += B[i][j];
            }
            j ++;
            if (j == B[i].size()) {
                if (search(root, temp) == 1) {
                    score ++;       
                }
                temp.clear();
            }
            j --;
        }
        scores[i] = score;
        score = 0;
        temp.clear();
    }
    int size = scores.size();
    map2.clear();
    for (int i = 0; i < size; i ++) {
        res.push_back(returnMaxIndex(scores, map2));
    }
    return res;
}
// Brute force solution
/*
int returnMaxIndex(vector<int> &A, unordered_map<int, int> &map) {
    int maxi = INT_MIN;
    int index = -1;
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] > maxi && map[i] != 1) {
            maxi = A[i];
            index = i;
        }
    }
    map[index] = 1;
    return index;
}
vector<int> Solution::solve(string A, vector<string> &B) {
    unordered_map<string, int> map;
    unordered_map<int, int> map2;
    string temp;
    for (int i = 0; i < A.size(); i ++) {
        if (A[i] == '_') {
            //cout << temp;
            map[temp] = 1;
            temp.clear();
        } else {
            temp += A[i];
        }
        i ++;
        if (i == A.size()) {
            //cout << temp;
            map[temp] = 1;
            temp.clear();
        }
        i --;
    }
    for (unordered_map<string, int>::iterator it = map.begin(); it != map.end(); it ++) {
        //cout << "key " << it -> first << " second " << it -> second << " ";
    }
    vector<int> scores(B.size()), res;
    temp = "";
    for (int i = 0; i < B.size(); i ++) {
        int score = 0;
        for (int j = 0; j < B[i].size(); j ++) {
            if (B[i][j] == '_') {
                //cout << temp << " ";
                if (map[temp] == 1) {
                    score ++;       
                }
                //map[temp] = 1;
                temp.clear();
            } else {
                temp += B[i][j];
            }
            j ++;
            if (j == B[i].size()) {
                //cout << temp;
                if (map[temp] == 1) {
                    score ++;       
                }
                temp.clear();
            }
            j --;
        }
        scores[i] = score;
        score = 0;
        temp.clear();
    }
    int size = scores.size();
    map2.clear();
    for (int i = 0; i < size; i ++) {
        res.push_back(returnMaxIndex(scores, map2));
    }
    return res;
}
*/