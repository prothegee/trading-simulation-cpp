#include <tradesim/utility_func.hh>

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
        return {.message = "unknown error occur", .result = RESULT_ERROR};
    }

    return {.message = "", .result = RESULT_OK};
}

} // namespace utility
} // namespace tradesim
