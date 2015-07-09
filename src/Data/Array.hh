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
  inline auto range(int start) -> fn<int,list<int>> {
    return [=](int end){
      return list<int>();
    };
  }

  template <typename A>
  inline auto length(list<A> l) {
    return l.size();
  }

  template <typename A>
  inline auto cons(A a) -> fn<list<A>, list<A>> {
    return [=](list<A> l) {
      return list<A>(a,l);
    };
  }

  // STUB!!!
  template <typename A, typename B>
  inline auto uncons_prime_(fn<Prelude::Unit,B> empty) {
    return [=](fn<A,fn<list<A>,B>> next) {
      return [=](list<A> xs) {
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
  const auto indexImpl = [](auto just) {
    return [=](auto nothing) {
      return [=](list<A> xs) {
        return [=](int i) {
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
  const auto findIndexImpl = [](auto just) {
    return nullptr;
  };

  // foreign import findLastIndexImpl :: forall a. (forall b. b -> Maybe b)
  //                                            -> (forall b. Maybe b)
  //                                            -> (a -> Boolean)
  //                                            -> Array a
  //                                            -> Maybe Int
  // STUB!!!
  template <typename A>
  const auto findLastIndexImpl = [](auto just) {
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
  const auto _updateAt = [](auto just) {
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
  const auto _insertAt = [](auto just) {
    return nullptr;
  };

  // STUB!!!
  template <typename A>
  inline auto _deleteAt(int i) {
    return [=](int n) {
      return [=](list<A> l) {
        return list<A>();
      };
    };
  }

  // STUB!!!
  template <typename A>
  inline auto reverse(list<A> l) {
    return list<A>();
  }

  // STUB!!!
  template <typename A>
  inline auto filter(fn<A,bool> f) {
    return [=](list<A> xs) {
      return list<A>();
    };
  }

  // STUB!!!
  template <typename A>
  inline auto slice(int s) {
    return [=](int e) {
      return [=](list<A> l) {
        return list<A>();
      };
    };
  }

  // STUB!!!
  template <typename A>
  inline auto sortImpl(fn<A,fn<A,int>> f) {
    return [=](list<A> l) {
      return list<A>();
    };
  }

  // STUB!!!
  template <typename A, typename B, typename C>
  inline auto zipWith(fn<A,fn<B,C>> f)  {
    return [=](list<A> xs) {
      return [=](list<B> ys) {
        return list<C>();
      };
    };
  }

}


#endif // Data_Array_FFI_HH
