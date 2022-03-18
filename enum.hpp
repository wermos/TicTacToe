#ifndef TIC_TAC_TOE_ENUM_HPP
#define TIC_TAC_TOE_ENUM_HPP

#include <cstdint> // for std::uint8_t

// This header file contains
enum class State : std::uint8_t {
	XWin,
	OWin,
	Draw,
	None,
};

enum class Move : std::uint8_t {
	None,
	X,
	O,
};

#endif // TIC_TAC_TOE_ENUM_HPP
