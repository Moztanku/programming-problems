#include <string>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int sign = 1;
        int result = 0;
        if (str.length() == 0) return 0;
        while (str[i] == ' ') {
            i++;
        }
        if (str[i] == '+' || str[i] == '-') {
            sign = (str[i++] == '+') ? 1 : -1;
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && str[i] - '0' > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            result = result * 10 + (str[i++] - '0');
        }
        return result * sign;
    }
};