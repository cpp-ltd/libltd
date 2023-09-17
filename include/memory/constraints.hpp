#ifndef LIBLTD_MEMORY_CONSTRAINTS_HPP
#define LIBLTD_MEMORY_CONSTRAINTS_HPP

#include <concepts>

namespace ltd::memory {

/**
 * Checks whether a type is a memory block type and is constructible from allocators.
 *
 * The allocator_constructable concept specifies that a variable of type T can be
 * initialized with pointer to void - representing raw pointer to allocated memory region - and
 * size_t - representing the size of allocated memory region.
 *
 * \tparam T The type to be checked.
 */
template <typename T>
concept allocator_constructable = std::constructible_from<T, void *, const std::size_t>;

/**
 * Checks whether a type is an allocator type.
 *
 * The allocatable concept specifies that a variable of type T represents an allocator, which can
 * allocate and deallocate memory blocks. It requires that the type's 'allocate' function returns a
 * type that satisfies the 'allocator_constructable' concept, and that its 'deallocate' function
 * returns 'void'.
 *
 * \tparam T The type to be checked.
 */
template <typename T>
concept allocatable = requires(T t, const std::size_t size) {
	{ t.allocate(size) } -> allocator_constructable;
};

}

#endif
