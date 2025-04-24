#include "core/Application.h"
#include "scenes/Assignment_1.h"
#include "scenes/Assignment_2.h"
#include "scenes/Assignment_3.h"
#include "scenes/Assignment_4.h"
#include "scenes/Assignment_5.h"
#include "scenes/TestScene.h"

int main(int argc, char** argv) {
    // Add newly created scenes here so that they show up in the menu.
    std::vector<Scene*> scenes = {
        new TestScene(),
        new Assignment_1(),
        new Assignment_2(),
        new Assignment_3(),
        new Assignment_4(),
        new Assignment_5(),
    };

    Application app(scenes);
    return app.Run();
}
