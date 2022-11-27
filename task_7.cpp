class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int pow = 10;
        int counter = 0; 
        const int INT_BEGIN = 214748364;
        if (x <= 0) {
            x = -x;
            while( x > 0) {
                if (counter == 9 && (res >  INT_BEGIN or (res ==  INT_BEGIN && x % 10 > 7)) {
                    return 0;
                }
                res *= pow;
                res += -(x % 10);
                x /= 10;
                ++counter;
            }
        }
        else {
            while( x > 0) {
                if (counter == 9 && (res <  -INT_BEGIN or (res ==  INT_BEGIN && x % 10 > 8)) {
                    return 0;
                }
                res *= pow;
                res += (x % 10);
                x /= 10;
                ++counter;
            }
        }
        return res;
    }
};