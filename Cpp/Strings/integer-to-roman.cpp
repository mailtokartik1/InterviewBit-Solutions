// Helper function to return the closest lower bound string/character of a number

string val(int A) {
    if (A >= 1000) {
        return "M";
    } else if (A >= 900) {
        return "CM";
    } else if (A >= 500) {
        return "D";
    } else if (A >= 400) {
        return "CD";
    } else if (A >= 100) {
        return "C";
    } else if (A >= 90) {
        return "XC";
    } else if (A >= 50) {
        return "L";
    } else if (A >= 40) {
        return "XL";
    } else if (A >= 10) {
        return "X";
    } else if (A >= 9) {
        return "IX";
    } else if (A >= 5) {
        return "V";
    } else if (A >= 4) {
        return "IV";
    } else if (A >= 1) {
        return "I";
    }
}

// Helper function to return the value associated with a number

int valAct(string B) {
    if (B == "M") {
        return 1000;
    } else if (B == "CM") {
        return 900;
    } else if (B == "D") {
        return 500;
    } else if (B == "CD") {
        return 400;
    } else if (B == "C") {
        return 100;
    } else if (B == "XC") {
        return 90;
    } else if (B == "L") {
        return 50;
    } else if (B == "XL") {
        return 40;
    } else if (B == "X") {
        return 10;
    } else if (B == "IX") {
        return 9;
    } else if (B == "V") {
        return 5;
    } else if (B == "IV") {
        return 4;
    } else if (B == "I") {
        return 1;
    }
}
string Solution::intToRoman(int A) {
    string B;
    string closest;
    B += closest;

    // Loop through the int and keep reducing the actual value
    // Keep increasing the closest value

    while (A > 0) {
        closest = val(A);
        B += closest;
        A -= valAct(closest);
    }
    return B;
}
