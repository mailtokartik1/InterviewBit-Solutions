// Helper function to add spaces

void addSpaces(string &a, int num) {
    for (int i = 0; i < num; i ++) {
        a += ' ';
    }
    return;
}
vector<string> Solution::fullJustify(vector<string> &A, int B) {
    vector<string> res;
    if (A.size() <= 0) {
        return res; 
    }
    int curSpace = 0;
    int blankspaces = 0;
    int start = 0;
    int realPlaces = 0;
    for (int i = 0; i < A.size(); i ++) {

        // Check capacity

        if (curSpace + A[i].size() < B) {
            curSpace += A[i].size() + 1;
            realPlaces += A[i].size();
        } else {
            if (curSpace + A[i].size() == B) {
                curSpace += A[i].size();
                realPlaces += A[i].size();
            } else i --;

            // Fill data into string

            int blankPortions = i - start;
            blankspaces = B - realPlaces;
            string temp;
            for (int j = start; j <= i; j ++) {
                temp += A[j];
                int dist = ceil(blankspaces / (double)(blankPortions));
                blankspaces -= dist;
                blankPortions --;
                addSpaces(temp, dist);
            }
            addSpaces(temp, B - temp.size());
            res.push_back(temp);
            start = i + 1;
            realPlaces = 0;
            curSpace = 0;
            blankspaces = 0;
        }
    }

    // Last line of the string vector

    string temp;
    for (int j = start; j <= A.size() - 1; j ++) {
        temp += A[j];
        if (j != A.size() - 1) {
            addSpaces(temp, 1);    
        } else {
            addSpaces(temp, B - temp.size());
        }
    }
    if (temp.size()) {
        res.push_back(temp);    
    }
    return res;
}

// Alternate solution

vector<string> Solution::fullJustify(vector<string> &A, int B) {

    // Corner case

    vector<string> C;
    if (A.size() <= 0 || B <= 0) {
        return C;
    }
    int lineSizeCount = 0;
    int startIndex = 0, endIndex = 0;

    // Loop through the string to add apply logic to add spaces in a line

    for (int i = 0; i < A.size(); i ++) {

        // Handler for the case when no. of characters in a line = B

        lineSizeCount += A[i].size();
        if (lineSizeCount == B) {
            endIndex = i;
            string temp;
            for (int j = startIndex; j <= endIndex; j ++) {
                temp += A[j];
                if (j != endIndex) {
                    temp += ' ';
                }
            }
            C.push_back(temp);
            startIndex = i + 1;
        }

        // Handler for the case when no. of characters in a line < B

        if (lineSizeCount > B) {
            lineSizeCount -= A[i].size() - 1;
            string temp;
            int lineWord = endIndex - startIndex + 1;
            int lineAreas = endIndex - startIndex;
            if (lineWord == 1) {
                lineAreas = 1;
            }
            int realLineSizeCount = 0;
            for (int j = startIndex; j <= endIndex; j ++) {
                realLineSizeCount += A[j].size();
            }
            int spaces = B - realLineSizeCount;
            if (lineWord == 1) {
                for (int j = startIndex; j <= endIndex; j ++) {
                    temp += A[j];
                }
                for (int j = 0; j < spaces; j ++) {
                    temp += ' ';
                }
                C.push_back(temp);
                startIndex = i;
                i --;
                lineSizeCount = 0;
                continue;
            }

            // check if the spaces are distributed equally

            if (spaces % lineAreas == 0) {
                int spaceLength = spaces / lineAreas;
                for (int j = startIndex; j <= endIndex; j ++) {
                    temp += A[j];
                    if (j != endIndex) {
                        for (int k = 0; k < spaceLength; k ++) {
                            temp += ' ';
                        }
                    }
                }
            } else {
                int spaceLength;

                // Logic to calculate spaces

                for (int j = startIndex; j <= endIndex; j ++) {
                    temp += A[j];
                    if (j != endIndex) {
                        if (lineAreas == 1) {
                            spaceLength = spaces;
                        } else {
                            spaceLength = ceil(spaces / (float)lineAreas);
                        }
                        for (int k = 0; k < spaceLength; k ++) {
                            temp += ' ';
                        }
                    }
                    spaces = spaces - spaceLength;
                    lineAreas --;
                }
            }
            if (temp.size() != 0) {
                C.push_back(temp);   
            }
            startIndex = i;
            i --;
            lineSizeCount = 0;
        } else {
            lineSizeCount ++;
            endIndex = i;
        }
    }
    string temp;

    // Last line handling logic

    if (lineSizeCount - 1 != B) {
        for (int j = startIndex; j <= endIndex; j ++) {
            temp += A[j];
            if (j != endIndex) {
                temp += ' ';
            }
        }
        if (B - temp.size()) {
            while(B - temp.size()) {
                temp += ' ';
            }
            C.push_back(temp);
        }
    }
    return C;
}
