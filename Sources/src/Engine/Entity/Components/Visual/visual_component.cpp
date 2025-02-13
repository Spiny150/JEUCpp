#include "visual_component.hpp"
#include <iostream>
#include "window_manager.h"
#include "entity.h"
#include "exceptions.h"
#include "assert.h"


VisualComponent::VisualComponent(Entity& entity, WindowManager* _WM, Camera* _camera) :
    Component(entity),
    WM(_WM),
    camera(_camera),
    renderLayer(0)
    {
        transform = entity.getComponent<TransformComponent>();
        assert(transform);

        std::cout << "VisualComponent instancié" << std::endl;
};


void VisualComponent::setRenderLayer(int renderLayer) {
    this->renderLayer = renderLayer;
    this->entity.getScene()->setEntityRenderLayer(&this->entity, this->renderLayer);
}
