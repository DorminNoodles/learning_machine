/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   learn.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:16:23 by lchety            #+#    #+#             */
/*   Updated: 2017/10/13 13:33:42 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define NB_OBJ 128
#define GROUND 40
#define GRAVITY 0.2
#define ENNEMY_DELAY 3

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

typedef struct s_player
{
	int		living;
	t_v2d	pos;
	t_v2d	velocity;
}t_player;

typedef struct s_dna
{
	int			jump;
	int			next_ennemy;
	int			frame;
	t_obj		obj[NB_OBJ];
	t_player	player;
}t_dna;
