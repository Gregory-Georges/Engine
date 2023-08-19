#type vertex
#version 410

layout (location = 0) in vec3 in_position;
layout (location = 1) in vec2 in_tex_coords;

uniform mat4 u_modelmat;
uniform mat4 u_viewprojmat;

out vec2 v_tex_coords;

void main()
{
    gl_Position = u_viewprojmat * u_modelmat * vec4(in_position, 1.0);
    v_tex_coords = in_tex_coords;
}



#type fragment
#version 410

out vec4 out_color;
in vec2 v_tex_coords;
uniform sampler2D u_texture;

void main()
{
    out_color = texture(u_texture, v_tex_coords);
}
