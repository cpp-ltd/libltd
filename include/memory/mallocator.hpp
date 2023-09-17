#ifndef LIBLTD_MEMORY_MALLOCATOR_HPP
#define LIBLTD_MEMORY_MALLOCATOR_HPP

#include "constraints.hpp"
#include "block.hpp"

namespace ltd::memory {

/**
 * Represents memory allocator that employs `malloc` - `free`.
 *
 * \tparam T The memory block type used.
 */
template <allocator_constructable T = block>
struct mallocator {

	[[nodiscard]] T
	allocate(const std::size_t size);

	void
	deallocate(T& block);

};

}

#endif
