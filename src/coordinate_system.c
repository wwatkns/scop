/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_system.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 16:27:51 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/10 18:33:45 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

void	set_projection_matrix(t_env *env, float fov)
{
	float	s;
	float	far;
	float	near;

	far = CAMERA_FAR;
	near = CAMERA_NEAR;
	s = 1 / (tan(fov * 0.5 * M_PI / 180.0));
	mat4_set(&env->sim.projection, 0);
	env->sim.projection.m[0] = s / env->win.ratio;
	env->sim.projection.m[5] = s;
	env->sim.projection.m[10] = -(far + near) / (far - near);
	env->sim.projection.m[11] = -1;
	env->sim.projection.m[14] = -2 * far * near / (far - near);
}

void	compute_mvp_matrix(t_env *env)
{
	env->sim.mvp = mat4_mul(mat4_transpose(env->sim.model),
		mat4_mul(env->sim.view, env->sim.projection));
}
