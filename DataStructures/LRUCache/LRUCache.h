#ifndef __LRU_CACHE_H__
#define __LRU_CACHE_H__
#include <list>
#include <system_error>
#include <unordered_map>

template <typename Key, typename Value>
class LRUCache {
private:
    template <typename K, typename V>
    struct Node {
        Node(K&& key, V&& value)
            : m_key(std::forward<K>(key)), m_value(std::forward<V>(value)) {}
        Key   m_key;
        Value m_value;
    };

public:
    using value_type = Node<Key, Value>;
    explicit LRUCache(std::size_t size) : m_size(size), m_currSize(0) {}

    const value_type* get(const Key& key) {
        auto it = m_map.find(key);
        if (it == m_map.end()) return nullptr;

        auto value = std::move(*it->second);
        m_cache.erase(it->second);
        m_cache.emplace_front(std::move(value));
        m_map[key] = m_cache.begin();
        return &(*m_map[key]);
    }

    template <typename K, typename... V>
    std::error_code add(K&& key, V... value) {
        if (m_size == m_currSize) {
            return std::make_error_code(std::errc::no_buffer_space);
        }

        if (m_map.find(key) != m_map.end()) {
            return std::make_error_code(std::errc::no_buffer_space);
        }
        m_cache.emplace_front(std::forward<K>(key),
                              std::forward<V...>(value...));
        m_map[key] = m_cache.begin();
        return std::error_code();
    }

private:
    std::size_t           m_size;
    std::size_t           m_currSize;
    std::list<value_type> m_cache;
    using ListIterator = typename std::list<value_type>::const_iterator;
    std::unordered_map<Key, ListIterator> m_map;
};

#endif
