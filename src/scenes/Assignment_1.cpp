//
// Created by ahsan on 23/04/2025.
//

#include "Assignment_1.h"

#include "imgui.h"
void Assignment_1::OnEnable() {
    for (auto& circle : circles) {
        circle.AddForce(gravity);
    }

    circles[0].velocity = glm::vec2(2.5, -5.0);
    circles[2].velocity = glm::vec2(-1.25, 0.5);

}
void Assignment_1::OnDisable() {}
void Assignment_1::Update(float deltaTime) {
    for (auto& circle : circles) {
        circle.Update(deltaTime);

        CollideFloor(floor, circle);
        CollideCeiling(ceiling, circle);
        CollideLeftWall(leftWall, circle);
        CollideRightWall(rightWall, circle);
    }


}

void Assignment_1::Draw() {
    for (auto& circle : circles) {
        circle.Draw();

        auto dot = glm::dot(circle.position - floor.start,
                            normalize((floor.end - floor.start)));

        Draw::Arrow(circle.position, floor.start + glm::vec2(1, 0) * dot);
    }
    floor.Draw();
    ceiling.Draw();
    leftWall.Draw();
    rightWall.Draw();
}
void Assignment_1::DrawGUI() {
    ImGui::Begin("Inspector");
    for (auto& circle : circles) {
        ImGui::DragFloat2("Circle Position", &circle.position[0]);
        ImGui::DragFloat2("Circle Velocity", &circle.velocity[0]);
    }
    ImGui::End();
}
void Assignment_1::CollideFloor(Line& line, Circle& circle) {
    auto dot = glm::dot(circle.position - line.start,
                        normalize((line.end - line.start)));
    auto point = line.start + glm::vec2(1, 0) * dot;

    if (glm::distance(circle.position, point) < circle.radius + 0.001f) {
        circle.position.y = point.y + (circle.radius + 0.001f);
        circle.velocity.y *= -1.0f;
    }
}
void Assignment_1::CollideCeiling(Line& line, Circle& circle) {
    auto dot = glm::dot(circle.position - line.start,
                        normalize((line.end - line.start)));
    auto point = line.start + glm::vec2(1, 0) * dot;

    if (glm::distance(circle.position, point) < circle.radius + 0.01f) {
        circle.position.y = point.y - (circle.radius + 0.01f);
        circle.velocity.y *= -1.0f;
    }
}
void Assignment_1::CollideLeftWall(Line& line, Circle& circle) {
    auto dot = glm::dot(circle.position - line.start,
                        normalize((line.end - line.start)));
    auto point = line.start + glm::vec2(0, 1) * dot;

    if (glm::distance(circle.position, point) < circle.radius + 0.01f) {
        circle.position.x = point.x + (circle.radius + 0.01f);
        circle.velocity.x *= -1.0f;
    }
}
void Assignment_1::CollideRightWall(Line& line, Circle& circle) {
    auto dot = glm::dot(circle.position - line.start,
                        normalize((line.end - line.start)));
    auto point = line.start + glm::vec2(0, 1) * dot;

    if (glm::distance(circle.position, point) < circle.radius + 0.01f) {
        circle.position.x = point.x - (circle.radius + 0.01f);
        circle.velocity.x *= -1.0f;
    }
}