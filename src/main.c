/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/12 11:38:18 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	glfw_loop(void)
{
	glfwPollEvents();
	glClearColor(0.09f, 0.08f, 0.15f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

int		main(int argc, char **argv)
{
	t_env	env;

	init(&env, argc, argv);
	load_obj(&env, env.model.filename);
	load_bmp(&env, "./resources/chaton.bmp");
	build_shader_program(&env);
	create_buffers(&env, GL_DYNAMIC_DRAW);
	glBindVertexArray(0);
	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(env.win.ptr))
	{
		glfw_loop();
		key_handle(&env);
		env.sim.model = mat4_mul(env.model.translation, env.model.rotation);
		glUseProgram(env.shader.program);
		compute_mvp_matrix(&env);
		update_shader_uniforms(&env);
		glBindTexture(GL_TEXTURE_2D, env.buffer.texture);
		glBindVertexArray(env.buffer.vao);
		glDrawElements(GL_TRIANGLES, env.model.num_indices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(env.win.ptr);
	}
	clean_glfw(&env);
	return (0);
}
