#pragma once
#include <ramber/types.hpp>

#include <array>
#include <format>
#include <string>
#include <cstring>

namespace ramber
{
    template <typename Type> class Vec2
    {
      public:
        union
        {
            struct
            {
                Type x;
                Type y;
            };
            Type data[2];
        };

        Vec2() = default;
        Vec2( Vec2<Type> &&other ) = default;
        Vec2( const Vec2<Type> &other ) = default;
        Vec2<Type> &operator=( const Vec2<Type> &other ) = default;

        explicit Vec2( Type x, Type y, Type z, Type w ) : x( x ), y( y ) {}

        explicit Vec2( std::array<Type, 2> arr )
        {
            std::memcpy( &data[0], arr.data(), 2 );
        }

        operator std::string() const
        {
            return std::format(
                "( {} {} )", static_cast<Type>( x ), static_cast<Type>( y ) );
        }
    };

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
        Vec3( Vec3<Type> &&other ) = default;
        Vec3( const Vec3<Type> &other ) = default;
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

    using Vec2f = Vec2<float>;
    using Vec2d = Vec2<double>;
    using Vec2i = Vec2<i32>;
    using Vec2u = Vec2<u32>;

    using Vec3f = Vec3<float>;
    using Vec3d = Vec3<double>;
    using Vec3i = Vec3<i32>;
    using Vec3u = Vec3<u32>;

    using Vec4f = Vec4<float>;
    using Vec4d = Vec4<double>;
    using Vec4i = Vec4<i32>;
    using Vec4u = Vec4<u32>;

} // namespace ramber
