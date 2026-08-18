class Solution {
public:
    int minAbsDifference(vector<int>&a, int s) {
        int n=a.size();
        int n1=n/2,n2=n-n/2;
    vector<int>a1;
    vector<int>a2;
    for(int i=0;i<n1;i++)a1.push_back(a[i]);
    for(int i=n1;i<n;i++)a2.push_back(a[i]);
    vector<int>s1;
    vector<int>s2;
    int sum=0;
    for(int m=0;m<(1<<n1);m++){
        sum=0;
        for(int i=0;i<n1;i++){
            if(m&(1<<i)){
                sum+=a1[i];
            }
        }
        s1.push_back(sum);
    }
    for(int m=0;m<(1<<n2);m++){
        sum=0;
        for(int i=0;i<n2;i++){
            if(m&(1<<i)){
                sum+=a2[i];
            }
        }
        s2.push_back(sum);
    }
    //sort(s1.begin(),s1.end());
    int close=INT_MAX;
    sort(s2.begin(),s2.end());
    for(int i=0;i<s1.size();i++){
        sum=s-s1[i];
        int it=lower_bound(s2.begin(),s2.end(),sum)-s2.begin();
        if(it<s2.size()){
            close=min(close,abs(s1[i]+s2[it]-s));
        }
        if(it>0)close=min(close,abs(s1[i]+s2[it-1]-s));
    }
    return close;
    }
};