#include "game_object.h"

GameObject::GameObject(std::shared_ptr<Sprite> sprite) : sprite_(sprite)
{
}

GameObject::~GameObject()
{
}

void GameObject::Draw()
{
    sprite_->Draw();
}
