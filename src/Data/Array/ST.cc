///////////////////////////////////////////////////////////////////////////////
//
// Module      :  ST.cc
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
#include "ST.hh"

namespace Data_Array_ST {
  using namespace PureScript;

  auto peekSTArrayImpl(const any& just) -> any {
    return [=](const any& nothing) -> any {
      return [=](const any& xs_) -> any {
        return [=](const any& i_) -> any {
          return [=]() -> any {
            const auto& xs = xs_.cast<STArray>();
            const auto i = i_.cast<long>();
            return i >= 0L && i < xs.size() ? just(xs[i]) : nothing;
          };
        };
      };
    };
  }

  auto pokeSTArray(const any& xs_) -> any {
    return [=](const any& i_) -> any {
      return [=](const any& a) -> any {
        return [=]() -> any {
          auto& xs = const_cast<STArray&>(xs_.cast<STArray>());
          const auto i = i_.cast<long>();
          const bool ret = i >= 0 && i < xs.size();
          if (ret){
            xs[i] = a;
          }
          return ret;
        };
      };
    };
  }

  auto pushAllSTArray(const any& xs_) -> any {
    return [=](const any& as_) -> any {
      return [=]() -> any {
        auto& xs = const_cast<STArray&>(xs_.cast<STArray>());
        const auto& as = as_.cast<any::vector>();
        xs.insert(xs.end(), as.begin(), as.end());
        return static_cast<long>(xs.size());
      };
    };
  }

  auto spliceSTArray(const any& xs_) -> any {
    return [=](const any& i_) -> any {
      return [=](const any& howMany_) -> any {
        return [=](const any& bs_) -> any {
          return [=]() -> any {
            auto& xs = const_cast<STArray&>(xs_.cast<STArray>());
            const auto i = i_.cast<long>();
            if (i < 0) {
              throw runtime_error("Negative index not supported yet");
            }
            const auto howMany = howMany_.cast<long>();
            const auto& bs = bs_.cast<any::vector>();
            any::vector removed;
            if (howMany > 0) {
              removed.insert(removed.begin(), xs.begin() + i, xs.begin() + i + howMany);
              xs.erase(xs.begin() + i, xs.begin() + i + howMany);
            }
            xs.insert(xs.begin() + i, bs.begin(), bs.end());
            return removed;
          };
        };
      };
    };
  }

  auto copyImpl(const any& xs) -> any {
    return [=]() -> any {
      return any::vector(xs.cast<STArray>());
    };
  }

  auto toAssocArray(const any& xs_) -> any {
    return [=]() -> any {
      const auto& xs = xs_.cast<STArray>();
      const auto n = xs.size();
      any::vector as;
      for (auto i = 0L; i < n; i++) {
        as.push_back( any::map { { KEY("value"), xs[i] }, { KEY("index"), i } } );
      }
      return as;
    };
  }

}
