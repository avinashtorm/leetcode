class Solution{
public:
    bool sumGame(string s){
        int n=s.size(),ls=0,rs=0,lq=0,rq=0;
        for(int i=0;i<n/2;i++){
            if(s[i]=='?')lq++;
            else ls+=s[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if(s[i]=='?')rq++;
            else rs+=s[i]-'0';
        }

        if((lq+rq)&1)return true;

        int diff=ls-rs;
        if(lq==rq)return diff!=0;

        if(lq>rq)return diff+9*(lq-rq)/2!=0;
        return diff-9*(rq-lq)/2!=0;
    }
};