#ifndef __FLY_WEIGHT_PATTERN_H__
#define __FLY_WEIGHT_PATTERN_H__

#include <string>
#include <unordered_map>
namespace FlyWeightPattern {

/**
 * The Flyweight pattern is fundametalyy a space saving technique. Its exact
 * incarnaation are diverse; sometimes you have the Flyweight being returned as
 * an API token that allows you to perform modification of whoever has spawned
 * it, ans sometimes the Flyweight is implicit, hiding behind the scene.
 */

using Key  = std::uint16_t;
using Map  = std::unordered_map<Key, std::string>;
using RMap = std::unordered_map<std::string, Key>;

struct User {
    User(const std::string& firstname, const std::string lastname)
        : m_firstname(add(firstname)), m_lastname(add(lastname)) {}

    const std::string& getFirstname() const {
        return s_names.find(m_firstname)->second;
    }

    const std::string& getLastname() const {
        return s_names.find(m_lastname)->second;
    }

protected:
    Key         m_firstname, m_lastname;
    static Map  s_names;
    static RMap s_keys;
    static Key  s_seed;
    static Key  add(const std::string& s);
};

}  // namespace FlyWeightPattern

#endif
