#pragma once
#include "glm/vec2.hpp"

class Circle {
public:
    glm::vec2 position{0,0};
    glm::vec2 velocity{0,0};
    glm::vec2 totalForce{0,0};
    float radius;

    Circle(glm::vec2 position, float radius)
        : position(position), radius(radius) {}

    void Draw() const;

    void Update(float deltaTime);
};