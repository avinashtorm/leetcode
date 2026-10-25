class LRUCache {
public:
int cap;
list<int>l;
unordered_map<int,pair<list<int>::iterator,int>>mp;
    LRUCache(int capacity) {
        cap=capacity;
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;
        l.erase(mp[key].first);
        l.push_front(key);
        mp[key].first=l.begin();
        return mp[key].second;
    }
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            l.erase(mp[key].first);
            mp.erase(key);
            l.push_front(key);
            mp[key]={l.begin(),value};
        }
        else if(cap>l.size()){
            l.push_front(key);
            mp[key]={l.begin(),value};
        }
        else{
            mp.erase(l.back());
            l.pop_back();
            l.push_front(key);
            mp[key]={l.begin(),value};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */