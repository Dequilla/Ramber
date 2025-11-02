#pragma once
#include <ramber/types.hpp>
#include <string>

namespace ramber
{

    template <typename Type> class Mat4
    {
      public:
        Type data[4][4] = { 0 };

        Mat4() = default;
        Mat4( Type all );
        Mat4(
            std::array<Type, 4> row1, std::array<Type, 4> row2,
            std::array<Type, 4> row3, std::array<Type, 4> row4 );
        static Mat4<Type> identity();

        Mat4( Mat4<Type> &other ) = default;
        Mat4( const Mat4<Type> &other ) = default;
        Mat4<Type> &operator=( const Mat4<Type> &other ) = default;

        operator std::string() const;

        void transpose();

        Mat4<Type> operator*( const Mat4<Type> &other ) const;
    };

    using Mat4f = Mat4<float>;
    using Mat4d = Mat4<double>;
    using Mat4i = Mat4<i32>;
    using Mat4u = Mat4<u32>;

} // namespace ramber

#include "mat.inl"
