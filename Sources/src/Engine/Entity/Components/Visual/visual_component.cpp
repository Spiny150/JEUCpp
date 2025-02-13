#include "visual_component.hpp"
#include <iostream>
#include "window_manager.h"
#include "entity.h"
#include "exceptions.h"
#include "assert.h"


VisualComponent::VisualComponent(Entity& entity, WindowManager* _WM, Camera* camera) :
    Component(entity),
    WM(_WM),
    renderLayer(0)
    {
        transform = entity.getComponent<TransformComponent>();
        assert(transform);
        camera = entity.getScene()->camera;
        assert(camera);

        std::cout << "VisualComponent instancié" << std::endl;
};

VisualComponent::~VisualComponent() {
    /*
    if (texture) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }
    if (srcRect) {
        delete srcRect;
        srcRect = nullptr;
    }*/
    std::cout << "VisualComponent détruit" << std::endl;
}

void VisualComponent::setRenderLayer(int renderLayer) {
    this->renderLayer = renderLayer;
    this->entity.getScene()->setEntityRenderLayer(&this->entity, this->renderLayer);
}

//WindowManager* VisualComponent::getWindowManager() {
//    assert(this->WM);
//    return this->WM;
//}
//
//Camera* VisualComponent::getCamera() {
//    assert(this->camera);
//    return this->camera;
//}
//
//TransformComponent* VisualComponent::getTransform() {
//    assert(this->transform);
//    return this->transform;
//}