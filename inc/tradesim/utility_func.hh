#ifndef TRADESIM_UTILITY_FUNC_HH
#define TRADESIM_UTILITY_FUNC_HH
#include <expected>
#include <random>
#include <string>

#include "config.hh"

namespace tradesim {
namespace utility {

static std::random_device _rand;
static std::default_random_engine _rande(_rand());

// --------------------------------------------------------- //
// find*

/// @brief
/// Replace source by replacement from query
///
/// @return tradesim::Result_t
Result_t find_and_replace_all(std::string& source, const std::string& query,
                              const std::string& replacement);

// --------------------------------------------------------- //
// file*

// --------------------------------------------------------- //
// gen*

template <typename T>
std::expected<T, std::string> generate_random_number(const T& min,
                                                     const T& max);

// --------------------------------------------------------- //
// read*

// --------------------------------------------------------- //
// write*

} // namespace utility
} // namespace tradesim

#endif // TRADESIM_UTILITY_FUNC_HH
