#include "Circle.h"

#include "core/Draw.h"

void Circle::Draw() const {
    Draw::Circle(position, radius);
}
void Circle::Update(float deltaTime) {
    velocity += totalForce * deltaTime;
    position += velocity * deltaTime;

}