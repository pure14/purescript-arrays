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

  using STArray = std::vector<any>;

  inline auto runSTArray(const any& f) -> any {
    return f;
  }

  inline auto emptySTArray() -> any {
    return STArray();
  }

  auto emptySTArray() -> any;

  auto peekSTArrayImpl(const any&) -> any;

  auto pokeSTArray(const any&) -> any;

  auto pushAllSTArray(const any&) -> any;

  auto spliceSTArray(const any&) -> any;

  auto copyImpl(const any&) -> any;

  auto toAssocArray(const any&) -> any;

}


#endif // Data_Array_ST_FFI_HH
