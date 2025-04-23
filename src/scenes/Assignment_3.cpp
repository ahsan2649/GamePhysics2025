//
// Created by ahsan on 23/04/2025.
//

#include "Assignment_3.h"

#include "imgui.h"
void Assignment_3::OnEnable() {}
void Assignment_3::OnDisable() {}
void Assignment_3::Update(float deltaTime) {
    if (deltaTime > 0.25) {
        deltaTime = 0.25;
    }

    dtAcc += deltaTime;

    while (dtAcc >= dt) {
        circle.totalForce = glm::vec2(0, 0);
        if (Input::IsMouseClicked(ImGuiMouseButton_Left)) {
            MouseStartPos = Input::GetMousePos();
        }

        if (Input::IsMouseDown(ImGuiMouseButton_Left)) {
            MouseEndPos = Input::GetMousePos();
        }

        if (Input::IsMouseReleased(ImGuiMouseButton_Left)) {
            auto launchVelocity = (MouseEndPos - MouseStartPos) * 100.0f * dt;
            circle.velocity += launchVelocity;
        }

        circle.AddForce(glm::vec2(0, -9.8));
        circle.Update(dt);

        CollideFloor(floor, circle);

        dtAcc -= dt;
    }
}

void Assignment_3::Draw() {
    if (Input::IsMouseDown(ImGuiMouseButton_Left)) {
        Draw::Arrow(MouseStartPos, MouseEndPos);


        auto position = circle.position;
        auto impulse = (MouseEndPos - MouseStartPos) * 100.0f * (1.0f/60.0f);
        auto velocity = circle.velocity + impulse;
        auto gravity = glm::vec2(0, -9.8);

        for (int i = 0; i < 50; ++i) {
            Draw::Circle(position, circle.radius);
            // Gravity acts continuously
            velocity += gravity * (1.0f/60.0f);
            position += velocity * (1.0f/60.0f);

        }
    }

        circle.Draw();
        floor.Draw();
}
void Assignment_3::DrawGUI() {}

void Assignment_3::CollideFloor(Line& line, Circle& circle) {
    auto dot = glm::dot(circle.position - line.start,
                        normalize((line.end - line.start)));
    auto point = line.start + glm::vec2(1, 0) * dot;

    if (glm::distance(circle.position, point) < circle.radius + 0.001f) {
        circle.position.y = point.y + (circle.radius + 0.001f);
        circle.velocity.y *= -0.75f;
        circle.velocity.x *= 0.75f;
    }
}