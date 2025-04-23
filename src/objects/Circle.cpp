#include "Circle.h"

#include "core/Draw.h"

void Circle::Draw() const {
    Draw::Circle(position, radius);
}
void Circle::Update(float deltaTime) {
    velocity += (totalForce / mass) * deltaTime;
    position += velocity * deltaTime;
}
void Circle::AddForce(glm::vec2 force) {
    totalForce += force * mass;
}