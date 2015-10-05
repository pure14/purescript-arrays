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

#include <algorithm>
#include "PureScript/PureScript.hh"

namespace Data_Array {
  using namespace PureScript;

  //------------------------------------------------------------------------------
  // Array creation --------------------------------------------------------------
  //------------------------------------------------------------------------------

  inline auto range(const any& start) -> any {
    return [=](const any& end) -> any {
      any::vector ns;
      for (auto i = start.cast<long>(); i <= end; i++ ) {
        ns.push_back(i);
      }
      return ns;
    };
  }

  inline auto replicate(const any& n) -> any {
    return [=](const any& v) -> any {
      any::vector vs;
      vs.insert(vs.begin(), n.cast<long>(), v);
      return vs;
    };
  }

  //------------------------------------------------------------------------------
  // Array size ------------------------------------------------------------------
  //------------------------------------------------------------------------------

  constexpr auto length(const any& xs) {
    return xs.cast<any::vector>().size();
  }


  //------------------------------------------------------------------------------
  // Extending arrays ------------------------------------------------------------
  //------------------------------------------------------------------------------

  inline auto cons(const any& e) -> any {
    return [=](const any& l_) {
      const auto& l = l_.cast<any::vector>();
      any::vector xs(e);
      xs.insert(xs.end(), l.begin(), l.end());
      return xs;
    };
  }

  inline auto snoc(const any& l_) -> any {
    return [=](const any& e) {
      const auto& l = l_.cast<any::vector>();
      any::vector xs(l);
      xs.push_back(e);
      return xs;
    };
  }

  //------------------------------------------------------------------------------
  // Non-indexed reads -----------------------------------------------------------
  //------------------------------------------------------------------------------

  inline auto uncons_prime_(const any& empty) {
    return [=](const any& next) {
      return [=](const any& xs_) {
        const auto& xs = xs_.cast<any::vector>();
        return xs.empty() ? empty() : next(xs.front())(any::vector(xs.begin() + 1, xs.end()));
      };
    };
  }

  //------------------------------------------------------------------------------
  // Indexed operations ----------------------------------------------------------
  //------------------------------------------------------------------------------

  inline auto indexImpl(const any& just) -> any {
    return [=](const any& nothing) -> any {
      return [=](const any& xs_) -> any {
        return [=](const any& i_) -> any {
          const auto& xs = xs_.cast<any::vector>();
          const long i = i_.cast<long>();
          return i < 0L || i >= xs.size() ? nothing : just(xs[i]);
        };
      };
    };
  };

  inline auto findIndexImpl(const any& just) -> any {
    return [=](const any& nothing) -> any {
      return [=](const any& f) -> any {
        return [=](const any& xs_) -> any {
          const auto& xs = xs_.cast<any::vector>();
          for (any::vector::const_iterator it = xs.begin(); it != xs.end(); ++it) {
            if (f(*it)) {
              return just(*it);
            }
          }
          return nothing;
        };
      };
    };
  };

  inline auto findLastIndexImpl(const any& just) -> any {
    return [=](const any& nothing) -> any {
      return [=](const any& f) -> any {
        return [=](const any& xs_) -> any {
          const auto& xs = xs_.cast<any::vector>();
          for (any::vector::const_reverse_iterator it = xs.rbegin(); it != xs.rend(); ++it) {
            if (f(*it)) {
              return just(*it);
            }
          }
          return nothing;
        };
      };
    };
  };

  inline auto _insertAt(const any& just) -> any {
    return [=](const any& nothing) -> any {
      return [=](const any& i_) -> any {
        return [=](const any& a) -> any {
          return [=](const any& l_) -> any {
            const auto i = i_.cast<long>();
            const auto& l = l_.cast<any::vector>();
            if (i < 0 || i > l.size()) {
              return nothing;
            }
            any::vector xs(l);
            xs.insert(xs.begin() + i, a);
            return just(xs);
          };
        };
      };
    };
  };


  inline auto _deleteAt(const any& just) -> any {
    return [=](const any& nothing) -> any {
      return [=](const any& i_) -> any {
        return [=](const any& l_) -> any {
          const auto i = i_.cast<long>();
          const auto& l = l_.cast<any::vector>();
          if (i < 0 || i >= l.size()) {
            return nothing;
          }
          any::vector xs(l);
          xs.erase(xs.begin() + i);
          return just(xs);
        };
      };
    };
  };

  inline auto _updateAt(const any& just) -> any {
    return [=](const any& nothing) -> any {
      return [=](const any& i_) -> any {
        return [=](const any& a) -> any {
          return [=](const any& l_) -> any {
            const auto i = i_.cast<long>();
            const auto& l = l_.cast<any::vector>();
            if (i < 0 || i >= l.size()) {
              return nothing;
            }
            any::vector xs(l);
            xs[i] = a;
            return just(xs);
          };
        };
      };
    };
  };

  //------------------------------------------------------------------------------
  // Transformations -------------------------------------------------------------
  //------------------------------------------------------------------------------

  inline auto reverse(const any& l) -> any {
    any::vector xs(l.cast<any::vector>());
    std::reverse(xs.begin(), xs.end());
    return xs;
  }

  inline auto concat(const any& xss_) -> any {
    const auto& xss = xss_.cast<any::vector>();
    const auto xss_length = xss.size();
    any::vector result;
    for (auto i = 0; i < xss_length; i++) {
      const auto& xs = xss[i].cast<any::vector>();
      const auto xs_length = xs.size();
      for (auto j = 0; j < xs_length; j++) {
        result.push_back(xs[j]);
      }
    }
    return result;
  }

  inline auto filter(const any& f) -> any {
    return [=](const any& xs_) -> any {
      const auto& xs = xs_.cast<any::vector>();
      any::vector result;
      for (auto it = xs.cbegin(); it != xs.cend(); ++it) {
        if (f(*it)) {
          result.push_back(*it);
        }
      }
      return result;
    };
  }

  //------------------------------------------------------------------------------
  // Sorting ---------------------------------------------------------------------
  //------------------------------------------------------------------------------

  inline auto sortImpl(const any& f) -> any {
    return [=](const any& xs_) -> any {
      const auto& xs = xs_.cast<any::vector>();
      any::vector result(xs);
      std::sort(result.begin(), result.end(),
                [f](const any& x, const any& y) { return (f(x)(y)) > 0L; } );
      return result;
    };
  }

  //------------------------------------------------------------------------------
  // Subarrays -------------------------------------------------------------------
  //------------------------------------------------------------------------------

  inline auto slice(const any& start) -> any {
    return [=](const any& end) -> any {
      return [=](const any& xs_) -> any {
        const auto& xs = xs_.cast<any::vector>();
        return any::vector(xs.begin() + start.cast<long>(), xs.begin() + end.cast<long>() + 1);
      };
    };
  }

  //------------------------------------------------------------------------------
  // Zipping ---------------------------------------------------------------------
  //------------------------------------------------------------------------------

  inline auto zipWith(const any& f) -> any {
    return [=](const any& xs_) -> any {
      return [=](const any& ys_) -> any {
        const auto& xs = xs_.cast<any::vector>();
        const auto& ys = ys_.cast<any::vector>();
        const auto length = std::min(xs.size(), ys.size());
        any::vector result;
        for (auto i = 0L; i < length; i++) {
          result.push_back(f(xs[i])(ys[i]));
        }
        return result;
      };
    };
  }

}


#endif // Data_Array_FFI_HH
