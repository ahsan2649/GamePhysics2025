
#pragma once
#include "core/Draw.h"
#include "glm/vec2.hpp"

class Line {
public:
    glm::vec2 start, end;
    Line(glm::vec2 start, glm::vec2 end) : start(start), end(end) {}
    ~Line() = default;

    void Draw() {
        Draw::Line(start, end);
    }
};
