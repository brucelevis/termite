#pragma once

#include "bx/bx.h"

// Export/Import Macro
// Export/Import API Def
#ifdef termite_SHARED_LIB
#ifdef termite_EXPORTS
#   if BX_COMPILER_MSVC
#       define TERMITE_API __declspec(dllexport) 
#   else
#       define TERMITE_API __attribute__ ((visibility("default")))
#   endif
#else
#   if BX_COMPILER_MSVC
#       define TERMITE_API __declspec(dllimport)
#   else
#       define TERMITE_API __attribute__ ((visibility("default")))
#   endif
#endif
#else
#   define TERMITE_API 
#endif

// Versioning Macros
#define T_MAKE_VERSION(_Major, _Minor)  (uint32_t)(((_Major & 0xffff)<<16) | (_Minor & 0xffff))
#define T_VERSION_MAJOR(_Ver) (uint16_t)((_Ver >> 16) & 0xffff)
#define T_VERSION_MINOR(_Ver) (uint16_t)(_Ver & 0xffff)
#define T_FAILED(_R) (_R) < 0
#define T_OK(_R) (_R) >= 0

namespace termite
{
    typedef int result_t;	// used for returning results see error_report and T_FAILED

    // Phantom types are used to define strong types that use the same base type
    // For example Phantom<int, TextureHandle>, Pantom<int, ResourceHandle>
    template <typename Tx, typename _Meaning, Tx _Invalid = 0>
    struct PhantomType
    {
        PhantomType()
        {
            value = _Invalid;
        }

        PhantomType(Tx _value) : value(_value)
        {
        }

        inline operator Tx()
        {
            return value;
        }

        inline bool isValid() const
        {
            return value != _Invalid;
        }

        inline void reset()
        {
            value = _Invalid;
        }

        Tx value;
    };
} // namespace termite