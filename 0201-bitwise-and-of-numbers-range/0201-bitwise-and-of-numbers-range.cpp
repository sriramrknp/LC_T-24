class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ZeroCount = 0;
        while(left < right){
            left >>= 1;
            right >>= 1;
            ZeroCount++;
        }
        return left << ZeroCount;
    }
};