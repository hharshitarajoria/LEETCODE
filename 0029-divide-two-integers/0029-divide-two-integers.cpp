class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        bool sign = true;  // positive
        if (dividend < 0 && divisor > 0)
            sign = false;
        if (dividend > 0 && divisor < 0)
            sign = false;
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long ans = 0;
        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += (1LL << cnt);
            n -= d << cnt;
        }
        if (sign && ans > INT_MAX)
            return INT_MAX;
        if (!sign && ans > 2147483648LL)
            return INT_MIN;
        return sign ? ans : -ans;
    }
};