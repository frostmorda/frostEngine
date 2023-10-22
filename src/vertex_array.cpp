#include "vertex_array.h"

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
