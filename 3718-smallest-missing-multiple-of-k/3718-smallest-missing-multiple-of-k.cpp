class Solution {
public:
    int missingMultiple(vector<int>& a, int k) {
        int ans,d=k;//=INT_MAX;
        while(1){
            if(find(a.begin(),a.end(),k)==a.end()){
                ans=k;
            break;
        }
        k+=d;
        }
        return ans;
    }
};