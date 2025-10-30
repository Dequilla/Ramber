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

    return 0;
}
