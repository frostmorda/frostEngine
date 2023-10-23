#include "vertex_array.h"

VertexArray::VertexArray(const VertexBuffer &vertex_buffer, const VertexBufferLayout &layout)
{
    Bind();
    vertex_buffer.Bind();
    const auto &layout_buffer = layout.GetBufferLayout();
    GLbyte *offset = nullptr;
    for (unsigned int i = 0; i < layout_buffer.size(); ++i)
    {
        const auto &current_layout_buffer = layout_buffer[i];
        glVertexAttribPointer(i, current_layout_buffer.size, current_layout_buffer.type, current_layout_buffer.normalize, layout.GetStride(), offset);
        glEnableVertexAttribArray(i);
        offset += current_layout_buffer.size * sizeof(GLfloat);
    }
}

VertexArray::VertexArray(VertexArray &&other) noexcept
{
    id_ = other.id_;
    other.id_ = 0;
}

VertexArray &VertexArray::operator=(VertexArray &&other) noexcept
{
    id_ = other.id_;
    other.id_ = 0;
    return *this;
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &id_);
}

void VertexArray::Bind() const
{
    glBindVertexArray(id_);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}
