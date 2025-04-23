#pragma once
#include "glm/vec2.hpp"

class Circle {
public:
    glm::vec2 position{0,0};
    glm::vec2 velocity{0,0};
    glm::vec2 totalForce{0,0};
    float mass;
    float radius;

    Circle(glm::vec2 position, float radius, float mass = 1)
        : position(position), radius(radius), mass(mass) {}

    void Draw() const;

    void Update(float deltaTime);

    void AddForce(glm::vec2 force);
};