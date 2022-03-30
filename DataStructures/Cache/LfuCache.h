#ifndef __LFU_CACHE_H__
#define __LFU_CACHE_H__

#include <iterator>
#include <list>
#include <unordered_map>

class LfuCache {
public:
    using Key      = int;
    using Value    = int;
    using Usage    = int;
    using Cache    = std::unordered_map<Key, Value>;
    using UsageMap = std::unordered_map<Key, Usage>;
    using FreqnMap = std::unordered_map<Usage, std::list<Key>>;

    constexpr static std::size_t s_maxSize = 5;

    explicit LfuCache(std::size_t capacity) : m_capacity(capacity) {}

    Value get(Key key) {}
    void  put(Key key, Value value) {}

private:
    std::size_t m_capacity;
    Usage       m_minUsage;
};

#endif  //__LFU_CACHE_H__
