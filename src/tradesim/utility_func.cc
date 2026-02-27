#include <tradesim/utility_func.hh>

#include <type_traits>

namespace tradesim {
namespace utility {

// --------------------------------------------------------- //
// find*

Result_t find_and_replace_all(std::string& source, const std::string& query,
                              const std::string& replacement) {
    try {
        size_t pos = 0;

        while ((pos = source.find(query, pos)) != std::string::npos) {
            source.replace(pos, query.size(), replacement);
            pos += replacement.size();
        }
    } catch (const std::exception& e) {
        return {.message = e.what(), .result = RESULT_EXECPTION};
    } catch (...) {
        return {.message = "Unknown error occur", .result = RESULT_ERROR};
    }

    return {.message = "", .result = RESULT_OK};
}

// --------------------------------------------------------- //
// gen*

template <typename T>
std::expected<T, std::string> generate_random_number(const T& min,
                                                     const T& max) {
    if constexpr (std::is_integral_v<T>) {
        std::uniform_int_distribution<T> eval(min, max);
        return eval(_rande);
    }

    if constexpr (std::is_same_v<T, float> || std::is_same_v<T, double>) {
        std::uniform_real_distribution<T> eval(min, max);
        return eval(_rande);
    }

    return std::unexpected("Expecting numerical type");
}

} // namespace utility
} // namespace tradesim
