#ifndef LIBLTD_MEMORY_MALLOCATOR_HPP
#define LIBLTD_MEMORY_MALLOCATOR_HPP

#include <cstdlib>
#include "allocator.hpp"

namespace ltd {

/**
 * \brief Represents memory allocator that employs `malloc` - `free`
 */
struct mallocator {

	[[nodiscard]] static block
	allocate(const std::size_t size)
	{
		if (! size) /* Avoid IDB */
			return null_block;

		void *ptr = std::malloc(size);
		if (ptr == nullptr)
			return null_block;

		return { ptr, size };
	}

	static void
	deallocate(block &blk)
	{
		free(blk.ptr);
		blk = null_block;
	}

};

}

#endif
