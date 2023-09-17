#ifndef LIBLTD_MEMORY_MALLOCATOR_HPP
#define LIBLTD_MEMORY_MALLOCATOR_HPP

#include <cstdlib>
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
	allocate(const std::size_t size)
	{
		if (! size)
			return T(nullptr, 0UL);

		void *ptr = std::malloc(size);
		if (ptr == nullptr)
			return T(nullptr, 0UL);

		return T(ptr, size);
	}

	void
	deallocate(T& block)
	{
		std::free(block.ptr);
		block = T(nullptr, 0UL);
	}

};

}

#endif
