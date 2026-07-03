class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        // If pattern is longer than text
        if (m > n)
            return -1;
        const long long BASE = 31;
        const long long MOD = 1000000007;
        long long power = 1;
        // Calculate BASE^(m-1) % MOD
        for (int i = 1; i < m; i++) {
            power = (power * BASE) % MOD;
        }
        long long patternHash = 0;
        long long windowHash = 0;
        // Compute hash of pattern and first window
        for (int i = 0; i < m; i++) {
            patternHash = (patternHash * BASE + (needle[i] - 'a' + 1)) % MOD;
            windowHash = (windowHash * BASE + (haystack[i] - 'a' + 1)) % MOD;
        }
        // Compare first window
        if (patternHash == windowHash) {
            if (haystack.substr(0, m) == needle)
                return 0;
        }
        // Slide the window
        for (int i = m; i < n; i++) {
            // Remove outgoing character
            windowHash = (windowHash -
                          ((haystack[i - m] - 'a' + 1) * power) % MOD
                          + MOD) % MOD;
            // Shift left and add incoming character
            windowHash = (windowHash * BASE +
                          (haystack[i] - 'a' + 1)) % MOD;
            // Hashes match
            if (windowHash == patternHash) {
                if (haystack.substr(i - m + 1, m) == needle)
                    return i - m + 1; //ending index-length+1
            }
        }
        return -1;
    }
};