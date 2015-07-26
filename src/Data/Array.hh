///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Array.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Array FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_Array_FFI_HH
#define Data_Array_FFI_HH

#include "Purescript/Purescript.hh"

namespace Data_Array {
  using namespace PureScript;

  // STUB!!!
  inline auto range(const int start) -> fn<int,array<int>> {
    return [=](const int end){
      return array<int>();
    };
  }

  template <typename A>
  inline auto length(const array<A>& l) {
    return l.size();
  }

  template <typename A>
  inline auto cons(param<A> a) -> fn<array<A>, array<A>> {
    return [=](const array<A>& l) {
      return array<A>(a,l);
    };
  }

  // STUB!!!
  template <typename A, typename B>
  inline auto uncons_prime_(const fn<Prelude::Unit,B>& empty) {
    return [=](const fn<A,fn<array<A>,B>>& next) {
      return [=](const array<A>& xs) {
        return empty();
      };
    };
  }

  // foreign import indexImpl :: forall a. (forall r. r -> Maybe r)
  //                                    -> (forall r. Maybe r)
  //                                    -> Array a
  //                                    -> Int
  //                                    -> Maybe a
  template <typename A>
  const auto indexImpl = [](const auto& just) {
    return [=](const auto& nothing) {
      return [=](const array<A>& xs) {
        return [=](const int i) {
          return i < 0 || i >= xs.size() ? nothing(typeval<A>) : just(typeval<A>)(xs[i]);
        };
      };
    };
  };

  // foreign import findIndexImpl :: forall a. (forall b. b -> Maybe b)
  //                                        -> (forall b. Maybe b)
  //                                        -> (a -> Boolean)
  //                                        -> Array a
  //                                        -> Maybe Int
  // STUB!!!
  template <typename A>
  const auto findIndexImpl = [](const auto& just) {
    return nullptr;
  };

  // foreign import findLastIndexImpl :: forall a. (forall b. b -> Maybe b)
  //                                            -> (forall b. Maybe b)
  //                                            -> (a -> Boolean)
  //                                            -> Array a
  //                                            -> Maybe Int
  // STUB!!!
  template <typename A>
  const auto findLastIndexImpl = [](const auto& just) {
    return nullptr;
  };

  // -- | Change the element at the specified index, creating a new array, or
  // -- | returning `Nothing` if the index is out of bounds.
  // updateAt :: forall a. Int -> a -> Array a -> Maybe (Array a)
  // updateAt = _updateAt Just Nothing
  //
  // foreign import _updateAt :: forall a. (forall b. b -> Maybe b)
  //                                    -> (forall b. Maybe b)
  //                                    -> Int
  //                                    -> a
  //                                    -> Array a
  //                                    -> Maybe (Array a)
  // STUB!!!
  template <typename A>
  const auto _updateAt = [](const auto& just) {
    return nullptr;
  };

  // foreign import _insertAt :: forall a. (forall b. b -> Maybe b)
  //                                    -> (forall b. Maybe b)
  //                                    -> Int
  //                                    -> a
  //                                    -> Array a
  //                                    -> Maybe (Array a)
  // STUB!!!
  template <typename A>
  const auto _insertAt = [](const auto& just) {
    return nullptr;
  };

  // STUB!!!
  template <typename A>
  inline auto _deleteAt(const int i) {
    return [=](const int n) {
      return [=](const array<A>& l) {
        return array<A>();
      };
    };
  }

  // STUB!!!
  template <typename A>
  inline auto reverse(const array<A>& l) {
    return array<A>();
  }

  // STUB!!!
  template <typename A>
  inline auto filter(const fn<A,bool>& f) {
    return [=](const array<A>& xs) {
      return array<A>();
    };
  }

  // STUB!!!
  template <typename A>
  inline auto slice(const int s) {
    return [=](const int e) {
      return [=](const array<A>& l) {
        return array<A>();
      };
    };
  }

  // STUB!!!
  template <typename A>
  inline auto sortImpl(const fn<A,fn<A,int>>& f) {
    return [=](const array<A>& l) {
      return array<A>();
    };
  }

  // STUB!!!
  template <typename A, typename B, typename C>
  inline auto zipWith(const fn<A,fn<B,C>>& f)  {
    return [=](const array<A>& xs) {
      return [=](const array<B>& ys) {
        return array<C>();
      };
    };
  }

}


#endif // Data_Array_FFI_HH
