///////////////////////////////////////////////////////////////////////////////
//
// Module      :  Unsafe.hh
// Copyright   :  (c) Andy Arvanitis 2015
// License     :  MIT
//
// Maintainer  :  Andy Arvanitis <andy.arvanitis@gmail.com>
// Stability   :  experimental
// Portability :
//
// Unsafe array FFI functions
//
///////////////////////////////////////////////////////////////////////////////
//
#ifndef Data_Array_Unsafe_FFI_HH
#define Data_Array_Unsafe_FFI_HH

#include "PureScript/PureScript.hh"

namespace Data_Array_Unsafe {
  using namespace PureScript;

  inline auto unsafeIndex(const any& xs) -> any {
    return [=](const any& n) -> any {
      return xs[n];
    };
  }
}

#endif // Data_Array_Unsafe_FFI_HH
