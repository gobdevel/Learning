#include "flyWeightPattern.h"

namespace FlyWeightPattern {

Key  User::s_seed = 0;
Map  User::s_names;
RMap User::s_keys;

Key User::add(const std::string& s) {
    if (auto it = s_keys.find(s); it != s_keys.end()) {
        return it->second;
    }

    ++s_seed;
    s_names[s_seed] = s;
    s_keys[s]       = s_seed;
    return s_seed;
}

}  // namespace FlyWeightPattern
