/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/08 17:26:25 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(void)
{
	t_env	env;

	init(&env);
	// parse_obj(&env, "../resources/42.obj");
	parse_obj(&env, "../resources/teapot2.obj");
	build_shader_program(&env, "../shader/vertex.glsl", "../shader/fragment.glsl");
	create_buffers(&env, GL_DYNAMIC_DRAW);
	glBindVertexArray(0);
	glEnable(GL_DEPTH_TEST);
	while(!glfwWindowShouldClose(env.win.ptr))
	{
		glfwPollEvents();
		glClearColor(0.09f, 0.08f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		key_handle(&env);
		env.sim.model = mat4_mul(env.model.rotation,
						mat4_mul(env.model.translation, env.model.scale));
		mat4_print(&env.sim.model);
		glUseProgram(env.shader.program);
		compute_mvp_matrix(&env);
		glUniformMatrix4fv(env.shader.mvploc, 1, GL_FALSE, env.sim.mvp.m);
		glUniform1i(env.shader.smdloc, env.mod.shading);
		glUniform1i(env.shader.cmdloc, env.mod.color);
		glBindVertexArray(env.buffer.VAO);
		glDrawElements(GL_TRIANGLES, env.model.num_indices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(env.win.ptr);
	}
	clean_glfw(&env);
	return (0);
}
