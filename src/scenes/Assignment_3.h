//
// Created by ahsan on 23/04/2025.
//

#pragma once
#include "core/Simple2DScene.h"
#include "objects/Circle.h"
#include "objects/Line.h"

class Assignment_3 : public Simple2DScene {
public:
    Assignment_3() {}
    ~Assignment_3() = default;

    void OnEnable() override;
    void OnDisable() override;
    void Update(float deltaTime) override;
    const char* GetName() override{return "Assignment_3";}
    void Draw() override;
    void DrawGUI() override;
    void CollideFloor(Line& line, Circle& circle);

private:
    glm::vec2 MouseStartPos{0, 0};
    glm::vec2 MouseEndPos{0, 0};

    Circle circle{glm::vec2(0, 5), 0.5};
    Line floor{glm::vec2(-4, -1), glm::vec2(4, -1)};

    float dtAcc = 0.0f;
    float dt = 0.001f;
};
