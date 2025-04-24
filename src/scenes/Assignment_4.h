//
// Created by ahsan on 24/04/2025.
//

#include "Assignment_1.h"
#include "core/Simple2DScene.h"
#include "objects/Circle.h"
#include "objects/Line.h"
class Assignment_4 : public  Simple2DScene {
public:
    void OnEnable() override;
    void OnDisable() override;
    void Update(float deltaTime) override;
    const char* GetName() override{return "Assignment_4";}
    void Draw() override;
    void DrawGUI() override;

private:
    Circle circle{glm::vec2{0, 3}, 0.5f};
    Line slantedFloor{ glm::vec2{-15, -3},glm::vec2{7, 3}};

    glm::vec2 gravity{0, -9.8};
    glm::vec2 origin{0, 0};

    bool Collide(glm::vec2 point, Circle circle);
    bool Collide(glm::vec2 point, Line line);
    bool Collide(Line line, Circle circle);
};



