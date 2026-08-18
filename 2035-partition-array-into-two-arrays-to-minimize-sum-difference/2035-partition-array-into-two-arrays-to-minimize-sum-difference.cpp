class Solution {
public:
    int minimumDifference(vector<int>& a) {
        int n=a.size();
        int s=accumulate(a.begin(),a.end(),0);
        int n1=n/2,n2=n1;
    vector<int>a1;
    vector<int>a2;
    for(int i=0;i<n1;i++)a1.push_back(a[i]);
    for(int i=n1;i<n;i++)a2.push_back(a[i]);
    unordered_map<int,vector<int>>s1;
    unordered_map<int,vector<int>>s2;
    int sum=0,count=0;
    for(int m=0;m<(1<<n1);m++){
        sum=0;
        count=0;
        for(int i=0;i<n1;i++){
            if(m&(1<<i)){
                sum+=a1[i];
                count++;
            }
        }
        s1[count].push_back(sum);
    }
    for(int m=0;m<(1<<n2);m++){
        sum=0;
        count=0;
        for(int i=0;i<n2;i++){
            if(m&(1<<i)){
                sum+=a2[i];
                count++;
            }
        }
        s2[count].push_back(sum);
    }
    int close=INT_MAX,need;
    for(int i=0;i<=n2;i++)sort(s2[i].begin(),s2[i].end());
    for(int i=0;i<=n1;i++){
        for(int j=0;j<s1[i].size();j++){
            if(s&1)need=s/2-s1[i][j]+1;
            else need=s/2-s1[i][j];
            int it=lower_bound(s2[n1-i].begin(),s2[n1-i].end(),need)-s2[n1-i].begin();
            if(it!=s2[n1-i].size())close=min(close,abs((s1[i][j]+s2[n1-i][it])*2-s));
            if(it>0)close=min(close,abs((s1[i][j]+s2[n1-i][it-1])*2-s));
        }
    }
    return close;

    }
};