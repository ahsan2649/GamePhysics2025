
#pragma once
#include "core/Draw.h"
#include "glm/vec2.hpp"

class Line {
public:
    glm::vec2 start, end;
    Line(glm::vec2 start, glm::vec2 end) : start(start), end(end) {}
    ~Line() = default;

    void Draw() { Draw::Line(start, end); }

    float GetLength() { return glm::distance(start, end); }

    glm::vec2 GetVector() const { return end - start; }

    glm::vec2 GetNormal() const {
        return {-GetVector().y, GetVector().x};
    }
};
