#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string generateTheString(int n) {
        if(n==0) return "";
        if(n==1) return "a";
        string s;
        if(n % 2 == 0) {
            s+="a";
            for(int k=0; k<n-1; k++) {
                s+="b";
            }
        }
        if(n % 2 != 0) {
            s+="a";
            s+="b";
            for(int k=0; k<n-2; k++) {
                s+="c";
            }
        }
        return s;
    }
};
int main() {
    Solution s;
    cout << s.generateTheString(4);
    return 0;
}
