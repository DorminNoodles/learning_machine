/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:16:23 by lchety            #+#    #+#             */
/*   Updated: 2017/10/12 14:39:23 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NB_OBJ 128

typedef struct s_v2d
{
	float	x;
	float	y;
} t_v2d;

typedef struct s_obj
{
	int		id;
	int		x;
	int		y;
	t_v2d	velocity;
}t_obj;

typedef struct s_dna
{
	t_obj	obj[NB_OBJ];
}t_dna;
