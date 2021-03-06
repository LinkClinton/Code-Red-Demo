#version 450
#extension GL_ARB_separate_shader_objects : enable

layout (set = 0, binding = 0) uniform View
{
    mat4 view;
} view;

layout (location = 0) in vec4 position;

void main()
{
    gl_Position = position * transpose(view.view);
}