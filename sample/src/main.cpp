#define RAMBER_IMPORT
#include <ramber/ramber.hpp>

#include <format>
#include <string>

int main( int argc, char **argv )
{
    ramber::hello_world();

    ramber::Vec4f vec{ 10.f, 10.f, 10.f, 10.f };
    std::cout << std::string( vec ) << std::endl;

    ramber::Mat4f mat = ramber::Mat4f::identity();
    std::cout << std::string( mat ) << std::endl;

    mat.data[3][0] = 10.f;
    std::cout << std::format( "\"{}\"", std::string( mat ) ) << std::endl;

    mat.transpose();
    std::cout << std::format( "\"{}\"", std::string( mat ) ) << std::endl;

    ramber::Mat4f t1{
        {1, 2, 3, 4},
        {1, 6, 3, 4},
        {1, 2, 6, 4},
        {1, 2, 3, 4}
    };

    ramber::Mat4f t2{
        {4, 3, 2, 1},
        {1, 2, 3, 4},
        {4, 3, 2, 1},
        {1, 2, 3, 4}
    };

    ramber::Mat4f mres{
        {22, 24, 26, 28},
        {26, 32, 38, 44},
        {34, 33, 32, 31},
        {22, 24, 26, 28}
    };

    std::cout << "Multiplied: \n" << std::string( t1 * t2 ) << std::endl;
    std::cout << "Result: \n" << std::string( mres ) << std::endl;

    ramber::Mat4f mv{
        {5, 2, 4, 1},
        {4, 3, 5, 3},
        {1, 2, 2, 4},
        {3, 6, 2, 3}
    };

    ramber::Vec4f vv{ 1, 4, 2, 3 };

    std::cout << "Matrix * Vector: " << std::string( mv * vv ) << " equals? "
              << std::string( ramber::Vec4f{ 24, 35, 25, 40 } ) << std::endl;
    // std::cout << "Matrix * Vector: " << std::string( vv * mv ) << std::endl;

    return 0;
}
