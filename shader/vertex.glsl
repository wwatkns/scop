#version 400 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec4	baseColor;

uniform vec3	ourMod;
uniform	float	ourAngle;

float	deg2rad(float angle)
{
	return angle * (3.1415926 / 180);
}

vec4	rotate3d_X(vec4 position)
{
	mat3	mat;
	vec3	tmp;
	float	theta;

	theta = deg2rad(ourAngle);
	mat[0] = vec3(1, 0, 0);
	mat[1] = vec3(0, cos(theta),-sin(theta));
	mat[2] = vec3(0, sin(theta), cos(theta));
	tmp = position.xyz * mat;
	return vec4(tmp.x, tmp.y, tmp.z, position.w);
}

vec4	rotate3d_Y(vec4 position)
{
	mat3	mat;
	vec3	tmp;
	float	theta;

	theta = deg2rad(ourAngle);
	mat[0] = vec3(cos(theta), 0, sin(theta));
	mat[1] = vec3(0, 1, 0);
	mat[2] = vec3(-sin(theta), 0, cos(theta));
	tmp = position.xyz * mat;
	return vec4(tmp.x, tmp.y, tmp.z, position.w);
}

vec4	rotate3d_Z(vec4 position)
{
	mat3	mat;
	vec3	tmp;
	float	theta;

	theta = deg2rad(ourAngle);
	mat[0] = vec3(cos(theta), -sin(theta), 0);
	mat[1] = vec3(sin(theta), cos(theta), 0);
	mat[2] = vec3(0, 0, 1);
	tmp = position.xyz * mat;
	return vec4(tmp.x, tmp.y, tmp.z, position.w);
}

void	main()
{
	vec4 newPosition;
	// gl_Position = vec4((position + ourMod * 0.5), 1.0);
	// gl_Position = rotate(vec4(position + ourMod * 0.5, 1.0));

	newPosition = rotate3d_X(vec4(position + ourMod * 0.3, 1.0));
	newPosition = rotate3d_Y(newPosition);
	newPosition = rotate3d_Z(newPosition);
	gl_Position = newPosition;
	baseColor = vec4(color, 1.0);
}
