#pragma once
#include <ramber/types.hpp>

#include <array>
#include <format>
#include <string>
#include <cstring>

namespace ramber
{
    template <typename Type> class Vec4
    {
      public:
        union
        {
            struct
            {
                Type x;
                Type y;
                Type z;
                Type w;
            };
            Type data[4];
        };

        Vec4() = default;
        Vec4( Vec4<Type> &&other ) = default;
        Vec4( const Vec4<Type> &other ) = default;
        Vec4<Type> &operator=( const Vec4<Type> &other ) = default;

        explicit Vec4( Type x, Type y, Type z, Type w )
            : x( x ), y( y ), z( z ), w( w )
        {
        }

        explicit Vec4( std::array<Type, 4> arr )
        {
            std::memcpy( &data[0], arr.data(), 4 );
        }

        operator std::string() const
        {
            return std::format(
                "( {} {} {} {} )", static_cast<Type>( x ),
                static_cast<Type>( y ), static_cast<Type>( z ),
                static_cast<Type>( w ) );
        }
    };

    using Vec4f = Vec4<float>;
    using Vec4d = Vec4<double>;
    using Vec4i = Vec4<i32>;
    using Vec4u = Vec4<u32>;

} // namespace ramber
