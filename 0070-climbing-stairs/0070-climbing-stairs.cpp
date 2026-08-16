class Solution {
public:
int t[46];
    int f(int n){
        
        if(n==0)return 1;
        else if(n<0)return 0;
        if(t[n]!=-1)return t[n];
        return t[n]=f(n-1)+f(n-2);
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return f(n);
    }
};