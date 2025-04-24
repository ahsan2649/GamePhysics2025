//
// Created by ahsan on 24/04/2025.
//

#include "Assignment_5.h"

#include "glm/ext/quaternion_geometric.hpp"
#include "imgui.h"
void Assignment_5::OnEnable() {}
void Assignment_5::OnDisable() {}

void Assignment_5::Update(float deltaTime) {
    for (auto& ball : poolBalls) {
        ball->totalForce = glm::vec2{0.0f};
    }

    if (Input::IsMouseClicked(ImGuiMouseButton_Left)) {
        MouseStart = Input::GetMousePos();
    }
    if (Input::IsMouseDown(ImGuiMouseButton_Left)) {
        MouseEnd = Input::GetMousePos();
    }
    if (Input::IsMouseReleased(ImGuiMouseButton_Left)) {
        auto impulse = (MouseEnd - MouseStart) * 200.0f;
        cueBall.velocity += impulse * deltaTime;
    }

    for (auto& ball : poolBalls) {
        for (auto& otherBall : poolBalls) {
            if (ball == otherBall) {
                continue;
            }

            if (Collide(*ball, *otherBall)) {
                float delta = (ball->radius + otherBall->radius) -
                              distance(ball->position, otherBall->position);

                auto ballDirection = normalize(ball->velocity);
                auto otherBallDirection =
                    normalize(otherBall->position - ball->position);

                auto ballU1 = ball->velocity;
                auto ballU2 = otherBall->velocity;
                auto ballV2 = otherBallDirection *
                              glm::dot(ball->velocity, otherBallDirection);
                auto ballV1 = ballU1 + ballU2 - ballV2;

                ball->velocity = ballV1;
                otherBall->velocity = ballV2;

                ball->position =
                    ball->position +
                    delta * normalize((ball->position - otherBall->position));
                otherBall->position =
                    otherBall->position +
                    delta * normalize((otherBall->position - ball->position));
            }
        }

        if (ball->position.x < left.start.x + ball->radius) {
            ball->velocity.x = -ball->velocity.x;
        }

        if (ball->position.x > right.start.x - ball->radius) {
            ball->velocity.x = -ball->velocity.x;
        }

        if (ball->position.y > top.start.y - ball->radius) {
            ball->velocity.y = -ball->velocity.y;
        }
        if (ball->position.y < bottom.start.y + ball->radius) {
            ball->velocity.y = -ball->velocity.y;
        }

        ball->velocity *= 0.98f;
    }

    for (auto& ball : poolBalls) {
        ball->Update(deltaTime);
    }
}
void Assignment_5::Draw() {
    for (auto& ball : poolBalls) {
        if (ball == &cueBall) {
            continue;
        }
        ball->Draw();
    }

    Draw::Circle(cueBall.position, cueBall.radius, true);

    for (auto& wall : walls) {
        auto dot = glm::dot(cueBall.position - wall->start,
                                        normalize(wall->GetNormal()));
        Draw::Arrow(
            cueBall.position,
            cueBall.position - normalize(wall->GetNormal()) * dot);
    }

    if (Input::IsMouseDown(ImGuiMouseButton_Left)) {
        Draw::Line(MouseStart, MouseEnd);
    }

    for (auto& line : walls) {
        line->Draw();
    }
}
void Assignment_5::DrawGUI() {


}

bool Assignment_5::Collide(Circle& ball, Circle& otherBall) {
    if (distance(ball.position, otherBall.position) <
        ball.radius + otherBall.radius) {
        return true;
        }
    return false;
}

