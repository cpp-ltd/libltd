#ifndef LIBLTD_MEMORY_BLOCK_HPP
#define LIBLTD_MEMORY_BLOCK_HPP

#include <utility>
#include <cstddef>

namespace ltd::memory {

/**
 * Represents a basic memory block.
 *
 * This type is the default allocator_constructable used by all allocatable types when no
 * allocator_constructable is provided.
 */
struct block {

	/**
	 * Raw pointer to allocated memory region.
	 */
	void *ptr;

	/**
	 * The size of the allocated memory region.
	 */
	std::size_t size;

	/**
	 * Constructs a memory block with the given pointer and size.
	 *
	 * \param p A raw pointer to the allocated memory region.
	 * \param s The size of the allocated memory region in bytes.
	 */
	block(void *p, const std::size_t s)
		: ptr { p }
		, size { s }
	{}

	/**
	 * Compares two memory blocks for equality.
	 *
	 * \param rhs The memory block to compare with.
	 * \return True if the memory blocks refer to the same memory region, false otherwise.
	 */
	inline bool
	operator==(const block &rhs) const
	{
		return (ptr == rhs.ptr) && (size == rhs.size);
	}

};

}

#endif
