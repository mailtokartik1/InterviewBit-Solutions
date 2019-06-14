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
