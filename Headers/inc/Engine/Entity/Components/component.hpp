#pragma once

class Entity;

class Component {
public:
    Entity& entity;
    explicit Component(Entity& _entity) : entity(_entity) {};
    virtual ~Component() = default;
};