// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        while(n){
            if(isBadVersion(n) == false) break;
            n--;
        }
        return n + 1;
    }
};