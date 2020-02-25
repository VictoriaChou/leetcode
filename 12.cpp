// 整数转罗马数字
#include <string>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        int arabicNumerals[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
        string romanNumerals[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };
        string res;
        for(int i = 12; i >= 0; i--){
            while(num >= arabicNumerals[i]) {
                num -= arabicNumerals[i];
                res += romanNumerals[i];
            }
        }
        return res;
    }
};
