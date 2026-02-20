#ifndef TRADEISM_CONFIG_HH
#define TRADEISM_CONFIG_HH
#include <cstdint>
#include <string>

#ifndef CPP_STANDARD
#define CPP_STANDARD @CMAKE_CXX_STANDARD @
#endif // CPP_STANDARD

#ifndef TRADESIM_IS_DEBUG
#define TRADESIM_IS_DEBUG @TRADESIM_IS_DEBUG @
#endif // TRADESIM_IS_DEBUG

#ifndef INLNSTTC
#define INLNSTTC inline static
#endif // INLNSTTC

#ifndef INLNSTTCCNST
#define INLNSTTCCNST inline static const
#endif // INLNSTTCCNST

// --------------------------------------------------------- //

namespace tradesim {

/// Result enum
enum Result_e : uint8_t {
    RESULT_OK,
    RESULT_ERROR,
    RESULT_EXECPTION,
}; // enum class Result_e

/// Result type
typedef struct _Result_t {
    std::string message;
    Result_e result;
} Result_t; // Result_t

} // namespace tradesim

// --------------------------------------------------------- //

#if defined(__GNUC__) || defined(__clang__)
#ifndef DEPRECATED
#define DEPRECATED(msg) __attribute__((deprecated(msg)))
#endif // DEPRECATED

#ifndef PRAGMA_MESSAGE_IMPL
#ifndef PRAGMA_MESSAGE
#define PRAGMA_MESSAGE_IMPL(str) _Pragma(#str)
// compiler independetn message
#define PRAGMA_MESSAGE(msg) PRAGMA_MESSAGE_IMPL(message msg)
#endif // PRAGMA_MESSAGE
#endif // PRAGMA_MESSAGE_IMPL
#elif defined(_MSC_VER)
#ifndef DEPRECATED
#define DEPRECATED(msg) __declspec(deprecated(msg))
#endif // DEPRECATED

#ifndef PRAGMA_MESSAGE
// compiler independetn message
#define PRAGMA_MESSAGE(msg) __pragma(message(msg))
#endif // PRAGMA_MESSAGE
#else
// n/a
#endif

#endif // TRADEISM_CONFIG_HH
