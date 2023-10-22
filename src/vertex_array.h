#ifndef SRC_VERTEX_ARRAY_H_
#define SRC_VERTEX_ARRAY_H_

#include <glad/glad.h>

class VertexArray
{
public:
    VertexArray() = delete;
    VertexArray(const VertexArray &) = delete;
    VertexArray &operator=(const VertexArray &) = delete;
    // VertexArray(const VertexBuffer &vertex_buffer, const VertexBufferLayout &layout);
    VertexArray(VertexArray &&other) noexcept;
    VertexArray &operator=(VertexArray &&other) noexcept;
    ~VertexArray();
    void Bind() const;
    void Unbind() const;

private:
    GLuint id_;
};
#endif // SRC_VERTEX_ARRAY_H_
