#ifndef PC_SNOWFLAKETYPE_HPP
#define PC_SNOWFLAKETYPE_HPP

#include <algorithm>
#include <cstdint>
#include <string>
#include <unordered_map>

namespace sf {

class SnowflakeType {
 public:
  enum class Type : uint8_t {
    ANY = 0,
    ARRAY = 1,
    BINARY = 2,
    BOOLEAN = 3,
    CHAR = 4,
    DATE = 5,
    FIXED = 6,
    OBJECT = 7,
    REAL = 8,
    TEXT = 9,
    TIME = 10,
    TIMESTAMP = 11,
    TIMESTAMP_LTZ = 12,
    TIMESTAMP_NTZ = 13,
    TIMESTAMP_TZ = 14,
    VARIANT = 15,
    VECTOR = 16,
    MAP = 17,
    DECFLOAT = 18,
    INTERVAL_YEAR_MONTH = 19,
    INTERVAL_DAY_TIME = 20,
  };

  static SnowflakeType::Type snowflakeTypeFromString(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return m_strEnumIndex.at(str);
  }

 private:
  static std::unordered_map<std::string, SnowflakeType::Type> m_strEnumIndex;
};

}  // namespace sf

#endif  // PC_SNOWFLAKETYPE_HPP
