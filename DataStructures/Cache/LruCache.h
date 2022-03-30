#ifndef __LRU_CACHE_H__
#define __LRU_CACHE_H__
#include <algorithm>
#include <list>
#include <system_error>
#include <unordered_map>

constexpr static std::size_t g_maxCapacity = 10;

// Below can be replaced by std::pair as well
template <typename Key, typename Value>
struct Node {
    template <typename K, typename... V>
    Node(K&& key, V&&... args)
        : m_key(std::forward<K>(key)), m_value(std::forward<V>(args)...) {}
    Key   m_key;
    Value m_value;
};

template <typename Key, typename Value>
class LruCache {
public:
    using ListNode     = Node<Key, Value>;
    using List         = std::list<ListNode>;
    using ListIterator = typename std::list<ListNode>::iterator;
    using HashMap      = std::unordered_map<Key, ListIterator>;

    explicit LruCache(std::size_t capacity) : m_capacity(capacity) {}

    template <typename K, typename... Args>
    std::error_code put(K&& key, Args&&... args) {
        if (m_map.find(key) != m_map.end()) {
            return std::make_error_code(std::errc::no_buffer_space);
        }

        if (m_capacity == g_maxCapacity) {
            // Remove from last
            auto delKey = m_list.back().m_key;
            m_map.erase(delKey);
            m_list.pop_back();
            --m_capacity;
        }

        // Add to list
        // ListNode node(key, std::forward<Args>(args)...);
        m_list.emplace_front(key, std::forward<Args>(args)...);
        // assert(it != m_list.end());
        m_map[key] = m_list.begin();
        ++m_capacity;
        return std::error_code();
    }

    std::pair<bool, ListIterator> get(const Key& key) {
        auto it = m_map.find(key);
        if (it == m_map.end()) {
            return {false, m_list.end()};
        }
        return {true, it->second};
    }

    void remove(const Key& key) {
        auto it = m_map.find(key);
        if (it == m_map.end()) return;
        m_list.erase(it->second);
        m_map.erase(it);
        --m_capacity;
    }

private:
    List        m_list;
    HashMap     m_map;
    std::size_t m_capacity;
};

#endif
