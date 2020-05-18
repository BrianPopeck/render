#include "Scene.h"

Scene::Scene() {}

std::shared_ptr<Scene> Scene::create() {
    return std::shared_ptr<Scene>(new Scene());
}
