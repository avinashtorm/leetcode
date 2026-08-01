class Solution {
public:
    int reverseBits(int n) {
        int ans=n&1;
        n>>=1;
        int x=31;
        while(x--){
            ans<<=1;
            ans=ans|(n&1);
            n>>=1;
        }
        return ans;
    }
};