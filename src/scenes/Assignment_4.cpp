//
// Created by ahsan on 24/04/2025.
//

#include "Assignment_4.h"

#include "imgui.h"
void Assignment_4::OnEnable() {}
void Assignment_4::OnDisable() {}
void Assignment_4::Update(float deltaTime) {
    auto dotOriginCircle = glm::dot(circle.position - slantedFloor.start,
                                    normalize(slantedFloor.GetNormal()));

    circle.totalForce = glm::vec2(0, 0);
    circle.AddForce(gravity);
    circle.Update(deltaTime);

    if (Collide(slantedFloor, circle)) {
        auto point = circle.position -
                     normalize(slantedFloor.GetNormal()) * dotOriginCircle;

        circle.position = point + (glm::normalize(slantedFloor.GetNormal()) *
                                   (circle.radius + 0.01f));

        circle.velocity = circle.velocity -
                          2.0f *
                              (glm::dot(circle.velocity,
                                        normalize(slantedFloor.GetNormal()))) *
                              normalize(slantedFloor.GetNormal());
    }
}
void Assignment_4::Draw() {
    circle.Draw();
    slantedFloor.Draw();

    auto dotOriginCircle = glm::dot(circle.position - slantedFloor.start,
                                    normalize(slantedFloor.GetNormal()));
    Draw::Arrow(circle.position,
                circle.position -
                    normalize(slantedFloor.GetNormal()) * dotOriginCircle);
}
void Assignment_4::DrawGUI() {
    ImGui::DragFloat2("Circle", &circle.position[0], 0.1f);
    ImGui::DragFloat2("Floor Start", &slantedFloor.start[0], 0.1f);
    ImGui::DragFloat2("Floor End", &slantedFloor.end[0], 0.1f);
}
bool Assignment_4::Collide(glm::vec2 point, Circle circle) {
    if (glm::distance(point, circle.position) < circle.radius) {
        return true;
    }

    return false;
}
bool Assignment_4::Collide(glm::vec2 point, Line line) {
    float combinedDistances =
        glm::distance(point, line.start) + glm::distance(point, line.end);
    if (combinedDistances >= line.GetLength() - 0.01f &&
        line.GetLength() + 0.01f >= combinedDistances) {
        return true;
    }

    return false;
}
bool Assignment_4::Collide(Line line, Circle circle) {
    if (Collide(line.start, circle) || Collide(line.end, circle)) {
        return true;
    }

    auto dotOriginCircle = glm::dot(circle.position - slantedFloor.start,
                                    normalize(slantedFloor.GetNormal()));

    auto point =
        circle.position - normalize(slantedFloor.GetNormal()) * dotOriginCircle;
    if (Collide(point, line)) {
        if (dotOriginCircle < circle.radius) {
            return true;
        }
    }

    return false;
}