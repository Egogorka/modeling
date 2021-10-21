//
// Created by Meevere on 21.10.2021.
//

#ifndef MODELING_TYPEDEFS_H
#define MODELING_TYPEDEFS_H

#include "KahanFloat.h"

#include <array>
#include <functional>

namespace modeling {

    template<typename T, std::size_t N>
    using Vector = std::array<T,N>;

    template<typename T>
    using Vector2 = Vector<T, 2>;

    // Very vague name for such function, but had no other variants
    template<typename Vec>
    using Operator = std::function<Vec(const Vec&)>;

    using Vector2f = Vector2<float>;
    using Vector2kf = Vector2<KahanFloat>;
}

#endif //MODELING_TYPEDEFS_H
