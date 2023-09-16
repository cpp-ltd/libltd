#ifndef LIBLTD_MEMORY_BLOCK_HPP
#define LIBLTD_MEMORY_BLOCK_HPP

#include <concepts>
#include <cstddef>

namespace ltd {

/**
 * \brief Represents dynamically allocated memory block.
 */
struct block {

	/** Raw pointer to the allocated region */
	void *ptr;

	/** The size of the allocated region */
	std::size_t size;

	/**
	 * \brief Checks whether blocks contain the same region.
	 * \param other The other block to compare.
	 * \return true if both contain the same region, false otherwise.
	 */
	inline bool
	operator==(const block& other) const
	{
		return ptr == other.ptr;
	}

};

/**
 * \brief Represents dynamically allocated memory block with reentrant
 * properties.
 * \todo Define the reentrant behavior and properties.
 */
struct reentrant_block { /* TODO */ };

/**
 * \brief Null or empty memory block.
 */
constexpr block null_block = { nullptr, 0UL };

/**
 * \brief The concept of memory blocks.
 * \todo Define actual constraints to satisfy this concept. Then, we would be
 * able to use this to customize memory block types with additional properties,
 * and it can be used like this:
 *
 * <template memory_block T = block>
 * struct mallocator;
 */
template<typename T>
concept memory_block = std::same_as<T, block>
                    || std::same_as<T, reentrant_block>;

}

#endif
