#include "Scene.h"
#include "Image.h"
#include "Camera.h"
#include "PinholeCamera.h"

int main()
{
    std::shared_ptr<Scene> scene = Scene::create();
    std::shared_ptr<Image> img = Image::create();
    std::shared_ptr<Camera> camera = PinholeCamera::create();

    std::string filename = std::string("myimage.ppm");

    // // TODO: delete temp code
    // // set up simple geometry by hand
    // scene->geometry.vertexList.push_back(Vector3(3.0f, 0.0f, -5.0f));
    // scene->geometry.vertexList.push_back(Vector3(0.0f, 3.0f, -5.0f));
    // scene->geometry.vertexList.push_back(Vector3(0.0f, 0.0f, -2.0f));
    // scene->geometry.indexList.push_back(0);
    // scene->geometry.indexList.push_back(1);
    // scene->geometry.indexList.push_back(2);

    // scene->geometry = IndexedTriangleList("teapot/teapot.obj");
    scene->geometry = IndexedTriangleList("untitled.obj");
    

    camera->render(*scene, *img);

    img->saveToDisk(filename);

    return 0;
}