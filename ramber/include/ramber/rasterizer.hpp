#pragma once
#include <functional>

#include "vec.hpp"
#include "mat.hpp"
#include "vertex.hpp"

namespace ramber
{

    // - User: Sends in vertices, indices, vertex shader, and fragment shader.
    // (Your steps 1 & 2)
    // - Rasterizer: Runs the Vertex Shader on each vertex individually to
    // transform it. (Your step 4)
    // - Rasterizer: Assembles the transformed vertices into triangles (using
    // the indices). (Your step 3)
    // - Rasterizer: Clips triangles, performs perspective divide, and maps them
    // to the screen. (Internal steps 2, 3, 4 from the doc)
    // - Rasterizer: Rasterizes the triangles (finds all covered pixels). (Your
    // step 5)
    // - Rasterizer: Runs the Fragment Shader for each of those pixels to
    // determine the final color. (Your step 6)

    using VertexShader = std::function<Vertex( Vertex )>;
    using FragmentShader = std::function<Vec4f( Vertex )>;

    class Rasterizer
    {
    };

} // namespace ramber
