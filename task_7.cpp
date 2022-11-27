class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int pow = 10;
        if (x <= 0) {
            x = -x;
            while( x > 0) {
                res *= pow;
                res += -(x % 10);
                x /= 10;
            }
        }
        else {
            while( x > 0) {
                res *= pow;
                res += (x % 10);
                x /= 10;
            }
        }
        return res;
    }
};