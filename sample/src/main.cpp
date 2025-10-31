#define RAMBER_IMPORT
#include <ramber/ramber.hpp>

#include <format>
#include <string>

int main( int argc, char **argv )
{
    ramber::hello_world();

    ramber::Vec3f vec{ 10.f, 10.f, 10.f };
    std::cout << std::string( vec ) << std::endl;

    ramber::Mat4f mat = ramber::Mat4f::identity();
    std::cout << std::string( mat ) << std::endl;

    mat.data[3][0] = 10.f;
    std::cout << std::format( "\"{}\"", std::string( mat ) ) << std::endl;

    mat.transpose();
    std::cout << std::format( "\"{}\"", std::string( mat ) ) << std::endl;

    ramber::Mat4f t1;
    float t1d[4][4] = {
        {1, 2, 3, 4},
        {1, 6, 3, 4},
        {1, 2, 6, 4},
        {1, 2, 3, 4}
    };
    memcpy( t1.data, t1d, sizeof( float ) * 4 * 4 );
    t1.transpose();

    ramber::Mat4f t2;
    float t2d[4][4] = {
        {4, 3, 2, 1},
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {1, 2, 3, 4}
    };
    memcpy( t2.data, t2d, sizeof( float ) * 4 * 4 );
    t2.transpose();

    ramber::Mat4f mres;
    float res[4][4] = {
        {22, 24, 26, 28},
        {26, 32, 38, 44},
        {34, 33, 32, 31},
        {22, 24, 26, 28}
    };
    memcpy( mres.data, res, sizeof( float ) * 4 * 4 );
    mres.transpose();

    std::cout << "Multiplied: \n" << std::string( t1 * t2 ) << std::endl;
    std::cout << "Result: \n" << std::string( mres ) << std::endl;

    return 0;
}
