class LRUCache{
public:
    LRUCache(int capacity) : _capacity(capacity) {}
    
    int get(int key) {
        auto it = _cache.find(key);
        if(it == _cache.end())
        	return -1;

        touch(it);
        return it->second.first;
    }
    
    void set(int key, int value) {
        auto it = _cache.find(key);
        if(it != _cache.end())
        	touch(it);
        else
        {
        	if(_cache.size() == _capacity)
        	{
        		_cache.erase(_used.back());
        		_used.pop_back();
        	}
        	_used.push_front(key);
        }
        _cache[key] = {value, _used.begin()};
    }

private:
	typedef list<int> Lt;
	typedef pair<int, Lt::iterator> Pit;
	typedef map<int, Pit> Cache;

	void touch(Cache::iterator it)
	{
		int key = it->first;
		_used.erase(it->second.second);
		_used.push_front(key);
		it->second.second = _used.begin();
	}

	Lt _used;
	Cache _cache;
	int _capacity;
};