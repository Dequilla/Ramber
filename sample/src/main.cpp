#define RAMBER_IMPORT
#include <ramber/ramber.hpp>

#include <format>

int main(int argc, char **argv) {
  ramber::hello_world();

  ramber::Vec3f vec{10.f, 10.f, 10.f};
  std::cout << std::string(vec) << std::endl;

  ramber::Mat4<float> mat = ramber::Mat4<float>::identity();
  std::cout << std::string(mat) << std::endl;

  std::cout << std::format("\"{}\"", std::string(mat)) << std::endl;
  return 0;
}
