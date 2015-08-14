///////////////////////////////////////////////////////////////////////////////
//
// Module      :  ST.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Array ST FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_Array_ST_FFI_HH
#define Data_Array_ST_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Array_ST {
  using namespace PureScript;

  // | A reference to a mutable array.
  // |
  // | The first type parameter represents the memory region which the array belongs to.
  // | The second type parameter defines the type of elements of the mutable array.
  // |
  template <typename H, typename A>
  using STArray = std::vector<A>;

  // foreign import peekSTArrayImpl :: forall a h e r. (a -> r) -> r -> (STArray h a) -> Int -> (Eff (st :: ST h | e) r)
  //
  template <typename A, typename H, typename R>
  const auto peekSTArrayImpl = [](const auto just) {
    return [=](const auto nothing) {
      return [=](const STArray<H,A>& xs) {
        return [=](const int i) {
          return [=]() -> R {
            return i >= 0 && i < xs.size() ? just(typeval<A>)(xs[i]) : nothing(typeval<A>);
          };
        };
      };
    };
  };

  // | Append the values in an immutable array to the end of a mutable array.
  // foreign import pushAllSTArray :: forall a h r. STArray h a -> Array a -> Eff (st :: ST h | r) Int
  //
  template <typename A, typename H>
  inline auto pushAllSTArray(const STArray<H,A>& xs) {
    return [=](const array<A>& as) {
      return [=]() -> int {
        xs.insert(xs.end(), as.begin(), as.end());
        return xs.size();
      };
    };
  }

  // foreign import copyImpl :: forall a b h r. a -> Eff (st :: ST h | r) b
  //
  template <typename A, typename B>
  inline auto copyImpl(param<A> xs) {
    return [=]() -> B {
      return A(xs);
    };
  }
}


#endif // Data_Array_ST_FFI_HH
