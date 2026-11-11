#pragma once

#include "utils/glm_utils.h"

namespace Transform2D {

    inline glm::mat3 Translate(float x, float y) {
        return glm::mat3(
            1, 0, 0,
            0, 1, 0,
            x, y, 1
        );
    }

    inline glm::mat3 Scale(float x, float y) {
        return glm::mat3(
            x, 0, 0,
            0, y, 0,
            0, 0, 1
        );
    }

    inline glm::mat3 Rotate(float radians) {
        float c = cos(radians);
        float s = sin(radians);

        return glm::mat3(
            c, s, 0,
            -s, c, 0,
            0, 0, 1
        );
    }
}
