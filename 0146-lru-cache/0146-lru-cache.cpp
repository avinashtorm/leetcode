class LRUCache {
public:
int ca;
unordered_map<int,int>mp;
list<int>l;
    LRUCache(int capacity){
      ca=capacity;  
    }
    int get(int key){
        if(mp.find(key)!=mp.end()){
            l.remove(key);
            l.push_back(key);
            return mp[key];
        }
        return -1;
    }
    void put(int key, int value){
        if(mp.find(key)!=mp.end()){
            l.remove(key);
            mp.erase(key);
            l.push_back(key);
            mp[key]=value;
        }
        else if(l.size()<ca){
            mp[key]=value;
            l.push_back(key);
        }
        else{
            mp.erase(l.front());
            l.pop_front();
            mp[key]=value;
            l.push_back(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */