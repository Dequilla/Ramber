#include <sstream>

namespace ramber
{

    template <typename Type> Mat4<Type>::Mat4( Type all )
    {
        for ( u32 x = 0; x < 4; x++ )
        {
            for ( u32 y = 0; y < 4; y++ )
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
        for ( u32 x = 0; x < 4; x++ )
        {
            ss << "[";
            for ( u32 y = 0; y < 4; y++ )
            {
                ss << " " << data[x][y];
            }
            ss << " ]\n";
        }
        return ss.str();
    }

} // namespace ramber
