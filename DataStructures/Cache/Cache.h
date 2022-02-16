#ifndef __CACHE_H__
#define __CACHE_H__

#include <list>
#include <system_error>
#include <unordered_map>
#include <utility>

/*
 * Array can not be used with O(1) because of iterator invalidity issue
 * LRU => ordering of entry must be maintain, so that last delete will work.
 */

template <typename Key, typename Value>
class LRUCache {
public:
    using value_type     = std::pair<Key, Value>;
    using iterator       = typename std::list<value_type>::iterator;
    using const_iterator = typename std::list<value_type>::const_iterator;

    explicit LRUCache(std::size_t capacity) : m_capacity(capacity) {}

    template <typename K, typename... Args>
    std::error_code insert(K&& key, Args... value) {
        auto iter = m_map.find(key);
        if (m_map.find(key) != m_map.end()) {
            m_cache.erase(iter->second);
        } else {
            if (m_capacity == m_cache.size()) {
                m_map.erase(m_cache.back().first);
                m_cache.pop_back();
            }
        }

        m_cache.emplace_front(key, std::forward<Args...>(value...));
        m_map[key] = m_cache.begin();
        return std::error_code();
    }

    template <typename K>
    std::pair<bool, const_iterator> get(K&& key) {
        if (auto iter = m_map.find(key); iter != m_map.end()) {
            auto value = std::move(*iter->second);
            m_cache.erase(iter->second);
            m_cache.emplace_front(std::move(value));
            m_map[key] = m_cache.begin();
            return {true, m_cache.begin()};
        }
        return {false, m_cache.end()};
    }

private:
    std::list<value_type>                   m_cache;
    std::unordered_map<Key, const_iterator> m_map;
    std::size_t                             m_capacity;
};

#endif
