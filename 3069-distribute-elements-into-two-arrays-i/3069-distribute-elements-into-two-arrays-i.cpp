class Solution {
public:
    vector<int> resultArray(vector<int>& a) {
        vector<int>a1,a2;
        a1.push_back(a[0]);
        a2.push_back(a[1]);
        for(int i=2;i<a.size();i++)a1.back()>a2.back()?a1.push_back(a[i]):a2.push_back(a[i]);
    a1.reserve(a1.size() + a2.size());
    a1.insert(a1.end(), a2.begin(), a2.end());
    return a1;
    }
};