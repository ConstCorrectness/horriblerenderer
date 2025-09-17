#ifndef HORRIBLE_CONTAINERS_HPP_
#define HORRIBLE_CONTAINERS_HPP_

#include <type_traits>

namespace horrible::utils
{


template<typename... Ts>
struct TypeContainer {
  static constexpr size_t count = sizeof...(Ts);
};


// primary class template: if instantiated, type T not in TypeContainer
template<typename T, typename... Ts>
struct idx {
  static constexpr int count = 0;
  static_assert(!std::is_same_v<T, T>, "T not in TypeContainer");
};


// partial class template specialization when TypeContainer's first type is T
template<typename T, typename... Ts>
struct idx<T, TypeContainer<T, Ts...>> {
  static constexpr int count = 0;
};

// partial class template specialization when TypeContainer's first type is U:
template<typename T, typename U, typename... Ts>
struct idx<T, TypeContainer<U, Ts...>> {
  static constexpr int count = 1 + idx<T, TypeContainer<Ts...>>::count;
};


}               // end namespace horrible::utils

#endif          // HORRIBLE_CONTAINERS_HPP_