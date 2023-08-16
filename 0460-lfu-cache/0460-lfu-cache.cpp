class LFUCache {
public:
    unordered_map<int, list<int>::iterator> ki; // key to iterator.
    unordered_map<int, pair<int,int>> kv; // key to {val, freq}.
    unordered_map<int, list<int>> fs; // frequency to a list of keys.

    int min_freq = 0; // current minimum frequency
    int sz = 0; // size 
    int cap; // capcity 


    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(kv.count(key)){
            /* Pop from the old queue and insert to the new freq + 1 queue */
            int old_freq = kv[key].second;
            fs[old_freq].erase(ki[key]);
            if(fs[min_freq].size() == 0){ // min_freq instead of old_freq
                min_freq ++;
            }
            fs[old_freq + 1].push_back(key);
            ki[key] = -- fs[old_freq + 1].end();
            kv[key].second ++;
            return kv[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        /* If key exists, update the value and increase the frequency */
        if(kv.count(key)){
            kv[key].first = value;
            get(key); // increase frequency
            return;
        }

        /* If cache is full, pop the oldest elemnt from the min_freq list */
        if(sz == cap){
            int evict_key = fs[min_freq].front();
            fs[min_freq].pop_front();
            kv.erase(evict_key);
            sz --;
        }
        
        /* Insert the new node into frequency-1 list */
        min_freq = 1;
        fs[min_freq].push_back(key);
        ki[key] = -- fs[min_freq].end();
        kv[key] = {value, 1};
        sz ++;
        
    }
};