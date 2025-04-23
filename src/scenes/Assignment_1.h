#pragma once
#include <vector>

#include "core/Simple2DScene.h"
#include "objects/Circle.h"
#include "objects/Line.h"

class Assignment_1 : public Simple2DScene {
public:
    Assignment_1() {}
    ~Assignment_1() = default;

    void OnEnable() override;
    void OnDisable() override;
    void Update(float deltaTime) override;
    void Draw() override;
    void DrawGUI() override;

    const char* GetName() override { return "Assignment_1"; }

private:
    std::vector<Circle> circles{{glm::vec2(-1, 1.75), 0.2f},
                                {glm::vec2(1, 1.5), 0.2f},
                                {glm::vec2(0, 1), 0.2f}};
    Line floor{glm::vec2(-2, -1), glm::vec2(2, -1)};
    Line ceiling{glm::vec2(-2, 2), glm::vec2(2, 2)};
    Line leftWall{floor.start, ceiling.start};
    Line rightWall{floor.end, ceiling.end};
    glm::vec2 gravity{0, -9.8f};

    void CollideFloor(Line &line, Circle &circle);
    void CollideCeiling(Line &line, Circle &circle);
    void CollideLeftWall(Line &line, Circle &circle);
    void CollideRightWall(Line &line, Circle &circle);
};
