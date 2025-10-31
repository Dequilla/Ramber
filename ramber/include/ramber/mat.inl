#pragma once
#include <ramber/mat.hpp>
#include <ramber/types.hpp>
#include <string>
#include <sstream>

namespace ramber
{

    template <typename Type> Mat4<Type>::Mat4( Type all )
    {
        for ( u32 y = 0; y < 4; y++ )
        {
            for ( u32 x = 0; x < 4; x++ )
            {
                data[x][y] = all;
            }
        }
    }

    template <typename Type> Mat4<Type> Mat4<Type>::identity()
    {
        Mat4<Type> m;
        m.data[0][0] = static_cast<Type>( 1 );
        m.data[1][1] = static_cast<Type>( 1 );
        m.data[2][2] = static_cast<Type>( 1 );
        m.data[3][3] = static_cast<Type>( 1 );
        return m;
    }

    template <typename Type> Mat4<Type>::operator std::string() const
    {
        std::stringstream ss;

        for ( u32 y = 0; y < 4; y++ )
        {
            ss << "[";
            for ( u32 x = 0; x < 4; x++ )
            {
                ss << " " << data[x][y];
            }
            ss << " ]\n";
        }
        return ss.str();
    }

    template <typename Type> void Mat4<Type>::transpose()
    {
        Mat4 newMat;
        for ( u32 y = 0; y < 4; y++ )
        {
            for ( u32 x = 0; x < 4; x++ )
            {
                newMat.data[y][x] = this->data[x][y];
            }
        }

        *this = newMat;
    }

    template <typename Type>
    Mat4<Type> Mat4<Type>::operator*( const Mat4<Type> &other ) const
    {
        Mat4<Type> n;
        for ( u32 y = 0; y < 4; y++ )
        {
            for ( u32 x = 0; x < 4; x++ )
            {
                n.data[x][y] = static_cast<Type>( 0 );
                for ( u32 inner = 0; inner < 4; inner++ )
                {
                    n.data[x][y] += this->data[inner][y] * other.data[x][inner];
                }
            }
        }

        return n;
    }
} // namespace ramber
