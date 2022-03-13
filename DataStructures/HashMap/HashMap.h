#ifndef __HASH_MAP_H__
#define __HASH_MAP_H__

#include <array>
#include <memory>
#include <system_error>

#include "utils.h"

template <typename Key, typename Value>
class HashMap {
private:
    static constexpr const std::size_t TABLE_SIZE{10};
    static constexpr const std::size_t PRIME{7};
    enum class State { EMPTY = 0, OCCUPIED, DELETED };
    struct Node {
        Node() = default;
        template <typename K, typename... T>
        Node(K&& key, T... args)
            : value(std::make_pair(std::forward<K>(key),
                                   std::forward<T...>(args...))),
              state(State::EMPTY) {}

        friend std::ostream& operator<<(std::ostream& stream, const Node& obj) {
            stream << static_cast<unsigned>(obj.state);
            if (obj.state == State::OCCUPIED) {
                stream << " => key: " << obj.value->first
                       << ", value: " << obj.value->second;
            }
            return stream;
        }
        std::unique_ptr<std::pair<Key, Value>> value;
        State                                  state{State::EMPTY};
    };
    using value_type = Node;

public:
    template <typename K, typename... V>
    std::error_code insert(K&& key, V... value) {
        static_assert(std::is_same_v<Key, remove_cv_ref_t<K>>,
                      "Keys are of not same type");
        if (m_size == TABLE_SIZE)
            return std::make_error_code(std::errc::not_enough_memory);

        auto index1 = getHash1(key);
        if (m_table[index1].state != State::OCCUPIED) {
            m_table[index1].value = std::make_unique<std::pair<Key, Value>>(
                std::forward<K>(key), std::forward<V...>(value...));
            m_table[index1].state = State::OCCUPIED;
            ++m_size;
        } else {
            auto        index2 = getHash2(key);
            std::size_t i      = 1;
            while (true) {
                auto newIndex = (index1 + i * index2) % TABLE_SIZE;
                if (m_table[newIndex].state != State::OCCUPIED) {
                    m_table[newIndex].value =
                        std::make_unique<std::pair<Key, Value>>(
                            std::forward<K>(key), std::forward<V...>(value...));
                    m_table[newIndex].state = State::OCCUPIED;
                    ++m_size;
                    break;
                }
                ++i;
            }
        }
        return std::error_code();
    }

    template <typename K>
    Value& operator[](K&& key) {
        auto index = getHash1(key);
        if (m_table[index].state != State::EMPTY) {
            auto i      = 0;
            auto index2 = getHash2(key);
            while (true) {
                auto newIndex = (index + i * index2) % TABLE_SIZE;
                if (m_table[newIndex].state == State::OCCUPIED &&
                    m_table[newIndex].value->first == key) {
                    return m_table[newIndex].value->second;
                }
                ++i;
            }
        }
    }

    template <typename K>
    void remove(K&& key) {
        if (m_size == 0) return;
        auto index1 = getHash1(key);
        if (m_table[index1].state == State::EMPTY) return;

        if (m_table[index1].state == State::OCCUPIED &&
            m_table[index1].value->first == key) {
            m_table[index1].value.reset(nullptr);
            m_table[index1].state = State::DELETED;
            --m_size;
        }

        // Store first key, for cleanup of all DELETED
        const auto firstIndex = index1;

        auto index2 = getHash2(key);

        std::size_t i = 1;
        while (true) {
            auto newIndex = (index1 + i * index2) % TABLE_SIZE;
            if (m_table[newIndex].state == State::EMPTY) break;

            if (m_table[newIndex].state == State::OCCUPIED &&
                m_table[newIndex].value->first == key) {
                m_table[newIndex].value.reset(nullptr);
                m_table[newIndex].state = State::DELETED;
                --m_size;
                break;
            }

            if (newIndex == index1) {
                // CLEANUP ALL DELETED
                break;
            }
            ++i;
        }
    }

    friend std::ostream& operator<<(std::ostream& stream, const HashMap& obj) {
        for (const auto& i : obj.m_table) {
            stream << i << "\n";
        }
        return stream;
    }

    std::size_t size() { return m_size; }

private:
    std::size_t getHash1(const Key& key) { return (key % TABLE_SIZE); }
    std::size_t getHash2(const Key& key) { return (PRIME - (key % PRIME)); }

    std::array<value_type, TABLE_SIZE> m_table;
    std::size_t                        m_size{0};
};

#endif
