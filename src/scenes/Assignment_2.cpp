//
// Created by ahsan on 23/04/2025.
//

#include "Assignment_2.h"

void Assignment_2::OnEnable() {
    circleOne.velocity = glm::vec2(0, -12);
    circleTwo.velocity = glm::vec2(0, -10);

    planetOne.velocity = glm::vec2(-.25, .25);
    planetTwo.velocity = glm::vec2(.75, -.5);
}

void Assignment_2::OnDisable() {}

void Assignment_2::Update(float deltaTime) {
    circleOne.totalForce = glm::vec2(0, 0);
    circleTwo.totalForce = glm::vec2(0, 0);

    circleOne.AddForce(glm::vec2(0, -9.8));
    circleTwo.AddForce(glm::vec2(0, -9.8));

    if (glm::distance(circleOne.position, forceFieldOne.position) < circleOne.radius + forceFieldOne.radius) {
        circleOne.AddForce(normalize((forceFieldOne.position - circleOne.position)) * forceFieldOne.mass);
    }

    if (glm::distance(circleTwo.position, forceFieldTwo.position) < circleTwo.radius + forceFieldTwo.radius) {
        circleTwo.AddForce(normalize((forceFieldTwo.position - circleTwo.position)) * forceFieldTwo.mass);
    }

    if (glm::distance(circleOne.position, forceFieldTwo.position) < circleOne.radius + forceFieldTwo.radius) {
        circleOne.AddForce(normalize((forceFieldTwo.position - circleOne.position)) * forceFieldTwo.mass);
    }

    if (glm::distance(circleTwo.position, forceFieldOne.position) < circleTwo.radius + forceFieldOne.radius) {
        circleTwo.AddForce(normalize((forceFieldOne.position - circleTwo.position)) * forceFieldOne.mass);
    }

    circleOne.Update(deltaTime);
    circleTwo.Update(deltaTime);

    CollideFloor(floor, circleOne);
    CollideFloor(floor, circleTwo);

    planetOne.totalForce = glm::vec2(0, 0);
    planetTwo.totalForce = glm::vec2(0, 0);

    planetOne.AddForce(normalize((planetTwo.position - planetOne.position)) * planetTwo.mass);
    planetTwo.AddForce(normalize((planetOne.position - planetTwo.position)) * planetOne.mass);

    planetOne.Update(deltaTime);
    planetTwo.Update(deltaTime);

}
void Assignment_2::Draw() {

    if (glm::distance(circleOne.position, forceFieldOne.position) < circleOne.radius + forceFieldOne.radius) {
        Draw::Arrow(circleOne.position, forceFieldOne.position);
    }

    if (glm::distance(circleTwo.position, forceFieldTwo.position) < circleTwo.radius + forceFieldTwo.radius) {
        Draw::Arrow(circleTwo.position, forceFieldTwo.position);

    }

    if (glm::distance(circleOne.position, forceFieldTwo.position) < circleOne.radius + forceFieldTwo.radius) {
        Draw::Arrow(circleOne.position, forceFieldTwo.position);
    }

    if (glm::distance(circleTwo.position, forceFieldOne.position) < circleTwo.radius + forceFieldOne.radius) {
        Draw::Arrow(circleTwo.position, forceFieldOne.position);
    }


    forceFieldOne.Draw();
    forceFieldTwo.Draw();

    circleOne.Draw();
    circleTwo.Draw();

    floor.Draw();

    planetOne.Draw();
    planetTwo.Draw();

}
void Assignment_2::DrawGUI() {}

void Assignment_2::CollideFloor(Line& line, Circle& circle) {
    auto dot = glm::dot(circle.position - line.start,
                        normalize((line.end - line.start)));
    auto point = line.start + glm::vec2(1, 0) * dot;

    if (glm::distance(circle.position, point) < circle.radius + 0.001f) {
        circle.position.y = point.y + (circle.radius + 0.001f);
        circle.velocity.y *= -1.0f;
    }
}