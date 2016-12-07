/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/07 15:34:54 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

// GLfloat vertices[] = {
// 	/* Positions */        /* Colors */
// 	-0.1f,  0.1f, -0.1f,  0.0f, 1.0f, 0.0f, // 0
// 	 0.1f,  0.1f, -0.1f,  0.0f, 0.0f, 1.0f, // 1
// 	 0.1f, -0.1f, -0.1f,  1.0f, 0.0f, 0.0f, // 2
// 	-0.1f, -0.1f, -0.1f,  0.0f, 1.0f, 1.0f, // 3
// 	-0.1f,  0.1f,  0.1f,  0.0f, 1.0f, 0.0f, // 4
// 	 0.1f,  0.1f,  0.1f,  0.0f, 0.0f, 1.0f, // 5
// 	 0.1f, -0.1f,  0.1f,  1.0f, 0.0f, 0.0f, // 6
// 	-0.1f, -0.1f,  0.1f,  0.0f, 1.0f, 1.0f  // 7
// };
//
// GLuint	indices[] = {
// 	/*	A cube has 6 faces, with 2 triangles/face, so 12 triangles total. */
// 	0, 1, 2,  0, 3, 2,  0, 4, 5,  0, 1, 5,  0, 4, 7,  0, 3, 7,
// 	6, 2, 1,  6, 5, 1,  6, 5, 4,  6, 7, 4,  6, 2, 3,  6, 7, 3
// };

int		main(void)
{
	t_env	env;

	init(&env);
	parse_model(&env);
	build_shader_program(&env, "../shader/vertex.glsl", "../shader/fragment.glsl");
	create_buffers(&env, GL_DYNAMIC_DRAW);
	glBindVertexArray(0);

	glEnable(GL_DEPTH_TEST);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	while(!glfwWindowShouldClose(env.win.ptr))
	{
		glfwPollEvents();
		glClearColor(0.09f, 0.08f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		key_handle(&env);

		env.sim.model = mat4_mul(env.model.rotation,
						mat4_mul(env.model.translation, env.model.scale));
		glUseProgram(env.shader.program);
		compute_mvp_matrix(&env);
		glUniformMatrix4fv(env.shader.mvploc, 1, GL_FALSE, env.sim.mvp.m);

		/*	Draw our rectangle using the shader program */
		glBindVertexArray(env.buffer.VAO);
		glDrawElements(GL_TRIANGLES, env.model.num_indices, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(env.win.ptr);
	}
	clean_glfw(&env);
	return (0);
}
