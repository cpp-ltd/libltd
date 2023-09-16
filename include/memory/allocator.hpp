#ifndef LIBLTD_ALLOCATOR_HPP
#define LIBLTD_ALLOCATOR_HPP

#include <cstddef>
#include "block.hpp"

namespace ltd {

/**
 * \brief The concept of allocators.
 */
template <typename T>
concept allocatable = requires(const std::size_t size) {
	{ T::allocate(size) } -> std::same_as<block>;
	{ T::deallocate(std::declval<block&>()) } -> std::same_as<void>;
};

}

#endif
