class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string temp = "";
        int count = 0;
        // till temp length= b's length
        while (temp.length() < b.length()) {
            temp += a;
            count++;
        }
        // b is present?
        if (temp.find(b) != string::npos) {
            return count;
        }
        // Add one more repetition
        temp += a;
        count++;
        if (temp.find(b) != string::npos) {
            return count;
        }
        return -1;
    }
};