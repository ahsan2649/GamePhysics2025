//
// Created by ahsan on 23/04/2025.
//
#pragma once
#include <vector>

#include "core/Simple2DScene.h"
#include "objects/Circle.h"
#include "objects/Line.h"

class Assignment_2 : public Simple2DScene {
public:
    Assignment_2() {}
    ~Assignment_2() = default;
    void OnEnable() override;
    void OnDisable() override;
    void Update(float deltaTime) override;
    const char* GetName() override { return "Assignment_2"; }
    void Draw() override;
    void DrawGUI() override;
    void CollideFloor(Line& line, Circle& circle);

private:
    Circle forceFieldOne {glm::vec2(-8, 5), 3, 4};
    Circle forceFieldTwo {glm::vec2(-3, 4), 3, 3};

    Circle circleOne {glm::vec2(-8.5, 2), 0.25, 1.5};
    Circle circleTwo {glm::vec2(-3.5, 1), 0.25, 1.25};

    Circle planetOne {glm::vec2(6, 2), 1, .5};
    Circle planetTwo {glm::vec2(9, 3), 0.75, .25};

    Line floor {glm::vec2(-9, 0), glm::vec2(2, 0)};
};
