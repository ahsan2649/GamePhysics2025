//
// Created by ahsan on 24/04/2025.
//
#pragma once
#include <vector>

#include "core/Simple2DScene.h"
#include "objects/Circle.h"
#include "objects/Line.h"

class Assignment_5 : public Simple2DScene {
public:
    void OnEnable() override;
    void OnDisable() override;
    bool Collide(Circle& ball, Circle& otherBall);
    void Update(float deltaTime) override;
    const char* GetName() override { return "Assignment_5"; }
    void Draw() override;
    void DrawGUI() override;

private:
    Circle cueBall{glm::vec2{0, 0}, 0.21};

    std::vector<Circle*> poolBalls = {
        &cueBall,
        new Circle{glm::vec2{0, 2}, 0.2},

        new Circle{glm::vec2{0.25, 2.5}, 0.2},
        new Circle{glm::vec2{-0.25, 2.5}, 0.2},

        new Circle{glm::vec2{0, 3}, 0.2},
        new Circle{glm::vec2{0.5, 3}, 0.2},
        new Circle{glm::vec2{-0.5, 3}, 0.2},

        new Circle{glm::vec2{0.25, 3.5}, 0.2},
        new Circle{glm::vec2{-0.25, 3.5}, 0.2},
        new Circle{glm::vec2{.75, 3.5}, 0.2},
        new Circle{glm::vec2{-.75, 3.5}, 0.2},
    };

    glm::vec2 MouseStart{0,0};
    glm::vec2 MouseEnd{0,0};

    Line top{glm::vec2{-2, 6}, glm::vec2{2, 6}};
    Line bottom{glm::vec2{-2, -2}, glm::vec2{2, -2}};
    Line left{top.start, bottom.start};
    Line right{top.end, bottom.end};

    std::vector<Line*> walls = {
        &top,
        &bottom,
        &left,
        &right,
    };

};
