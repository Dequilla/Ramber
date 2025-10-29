#pragma once
#include <ramber/types.hpp>

#include <array>
#include <format>
#include <string>
#include <cstring>

namespace ramber
{

    template <typename Type> class Vec3
    {
      public:
        union
        {
            struct
            {
                Type x;
                Type y;
                Type z;
            };
            Type data[3];
        };

        Vec3() = default;
        explicit Vec3( Vec3<Type> &&other ) = default;
        explicit Vec3( const Vec3<Type> &other ) = default;
        Vec3<Type> &operator=( const Vec3<Type> &other ) = default;

        explicit Vec3( Type x, Type y, Type z ) : x( x ), y( y ), z( z ) {}
        explicit Vec3( std::array<Type, 3> arr )
        {
            std::memcpy( &data[0], arr.data(), 3 );
        }

        operator std::string() const
        {
            return std::format(
                "( {} {} {} )", static_cast<Type>( x ), static_cast<Type>( y ),
                static_cast<Type>( z ) );
        }
    };

    using Vec3f = Vec3<float>;
    using Vec3d = Vec3<double>;
    using Vec3i = Vec3<i32>;
    using Vec3u = Vec3<u32>;

} // namespace ramber
