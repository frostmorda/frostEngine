#ifndef SRC_GAME_OBJECT_H_
#define SRC_GAME_OBJECT_H_

#include <memory>
#include <glm/glm.hpp>
#include <glad/glad.h>

#include "../engine/sprite.h"
class GameObject
{
public:
    GameObject(std::shared_ptr<Sprite> sprite);
    ~GameObject();
    void Draw();

private:
    std::shared_ptr<Sprite> sprite_;
    glm::vec2 position_;
    glm::vec2 size_;
    glm::vec3 color_;
    float rotation_;
};
#endif // SRC_GAME_OBJECT_H_
