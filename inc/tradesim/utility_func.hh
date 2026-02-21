#ifndef TRADESIM_UTILITY_FUNC_HH
#define TRADESIM_UTILITY_FUNC_HH
#include <expected>
#include <string>

#include "config.hh"

namespace tradesim {
namespace utility {

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

// --------------------------------------------------------- //
// read*

// --------------------------------------------------------- //
// write*

} // namespace utility
} // namespace tradesim

#endif // TRADESIM_UTILITY_FUNC_HH
