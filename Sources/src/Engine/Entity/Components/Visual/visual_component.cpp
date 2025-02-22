#include "visual_component.hpp"
#include <iostream>
#include "window_manager.h"
#include "entity.h"
#include "exceptions.h"
#include "assert.h"

// VisualComponent constructor
VisualComponent::VisualComponent(Entity& entity, WindowManager* _WM, Camera* _camera) :
    Component(entity),
    WM(_WM),
    camera(_camera),
    renderLayer(0),
    isActive(true)
{
    // Get transform component from entity
    transform = entity.getComponent<TransformComponent>();
    assert(transform);

    std::cout << "VisualComponent instantiated" << std::endl;
}

// Set the render layer for this visual component
void VisualComponent::setRenderLayer(int renderLayer) {
    this->renderLayer = renderLayer;
    // Update entity's render layer in the scene
    this->entity.getScene()->setEntityRenderLayer(&this->entity, this->renderLayer);
}
