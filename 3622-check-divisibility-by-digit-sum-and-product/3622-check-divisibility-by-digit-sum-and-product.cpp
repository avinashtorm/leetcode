class Solution {
public:
    bool checkDivisibility(int n) {
        int l=n;
        int s=0,p=1;
        while(n){
            int k=n%10;
            s+=k;
            p*=k;
            n/=10;
        }
        return !bool(l%(s+p));
    }
};