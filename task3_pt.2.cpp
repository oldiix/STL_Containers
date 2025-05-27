#include <algorithm>
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>

class LRUCache
{
    int capacity;
    std::list<int> cache;
    std::unordered_map<int, std::list<int>::iterator> map;

    public:
    LRUCache(int capacity) : capacity(capacity) {}

    void access(int key)
    {
        auto it = map.find(key);
        if (it != map.end())
        {
            cache.erase(it->second);
        } else if(cache.size() == capacity)
        {
            int last = cache.back();
            cache.pop_back();
            map.erase(last);
        }
        cache.push_front(key);
        map[key] = cache.begin();
    }
    void display() const
    {
        for(int k : cache)
            std::cout << k << " ";
        std::cout << std::endl;
    }
};

int main()
{
    LRUCache lrucache(5);
    std::vector<int> accesses = {1, 2, 3, 4, 5, 6, 7};

    std::ranges::for_each(accesses,[&lrucache](int key)
    {
        lrucache.access(key);
        lrucache.display();
    });

    return 0;
}