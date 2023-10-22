#ifndef SRC_VERTEX_BUFFER_H_
#define SRC_VERTEX_BUFFER_H_

#include <glad/glad.h>

class VertexBuffer
{
public:
    VertexBuffer() = delete;
    VertexBuffer(const VertexBuffer &) = delete;
    VertexBuffer &operator=(const VertexBuffer &) = delete;
    VertexBuffer(const void *data, const unsigned int size);
    VertexBuffer(VertexBuffer &&other);
    VertexBuffer &operator=(VertexBuffer &&other);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;
    void Update(const void *data, const unsigned int size) const;

private:
    GLuint id_;
};
#endif // SRC_VERTEX_BUFFER_H_
