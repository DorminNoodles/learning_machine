/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:04:58 by lchety            #+#    #+#             */
/*   Updated: 2017/10/12 22:10:02 by lchety           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <stdlib.h>
#include <unistd.h>
#include "learn.h"
#include "libft.h"

void	create_ennemy(t_dna *dna, int x, int y)
{
	int i;

	i = 0;
	while (i < NB_OBJ && dna->obj[i].id != -1)
		i++;
	if (i == NB_OBJ)
	{
		printw("No more space for obj\n");
		return ;
	}

	dna->obj[i].id = i;
	dna->obj[i].x = x;
	dna->obj[i].y = y;
	dna->obj[i].velocity.x = -1.0;
	dna->obj[i].velocity.y = 0.0;

}

void	create_player(t_dna *dna)
{


}

void	physics_player(t_dna *dna)
{
	if (dna->player.pos.y + dna->player.velocity.y > GROUND)
	{
		dna->player.velocity.y = 0;
		dna->player.pos.y = GROUND;
		dna->jump = 0;
	}
	else
	{
		dna->player.velocity.y += GRAVITY;
	}

	dna->player.pos.y += dna->player.velocity.y;
}

void	physics(t_dna *dna)
{
	int i;

	i = 0;
	while (i < NB_OBJ)
	{
		if (dna->obj[i].id != -1)
		{
			dna->obj[i].x += dna->obj[i].velocity.x;
			// move(dna->obj[i].x, dna->obj[i].y);
			// printw("%d\n", dna->obj[i].x);
			//printw("%d\n", dna->obj[i].y);
			// move(dna->obj[i].x, dna->obj[i].y);
			// printw("X");
			// printw("foo\n");
			// printw("ta mere\n");
		}
		i++;
	}
	physics_player(dna);

}

void	controller(t_dna *dna)
{
	int keycode;

	// printw("SPACE");
	// nocbreak(); //getch() no block
	keycode = getch();

	if (keycode == ' ' && !dna->jump)
	{
		dna->jump = 1;
		// printw("SPACE");
		dna->player.velocity.y -= 1.4;
	}
	// printw("keycode : %d\n", keycode);


}

void	display_player(t_dna *dna)
{
	move(dna->player.pos.y, dna->player.pos.x);
	printw("P");
}

void	display(t_dna *dna)
{
	int i;

	i = 0;
	while (i < NB_OBJ)
	{
		if (dna->obj[i].id != -1)
		{

			if (dna->obj[i].x >= 0 && dna->obj[i].x < COLS)
			{
				if (dna->obj[i].y >= 0 && dna->obj[i].y < LINES)
				{
					// printw("%d     %d", dna->obj[i].x, dna->obj[i].y);
					move(dna->obj[i].y, dna->obj[i].x);
					printw("X");
					// move(LINES - 1, COLS - 1);
					curs_set(0);
				}
			}
		}
		i++;
	}
	display_player(dna);

}

void	init_dna(t_dna *dna)
{
	int i;

	i = 0;
	ft_bzero(dna->obj, NB_OBJ);
	while (i < NB_OBJ)
	{
		dna->obj[i].id = -1;
		i++;
	}

	dna->next_ennemy = dna->frame + ENNEMY_DELAY;
}

void	init_player(t_dna *dna)
{
	dna->player.pos.y = 20;
	dna->player.pos.x = 25;
	dna->player.velocity.y = 0.0;
	dna->player.living = 1;
}

void	collisions(t_dna *dna)
{
	if ((int)dna->player.pos.x == dna->obj[0].x)
	{
		if ((int)dna->player.pos.y == dna->obj[0].y)
		{
			dna->player.living = 0;
		}
	}

}

void	main_game(t_dna *dna)
{
	while (dna->player.living)
	{
		clear();
		//------debug
			// move(0,0);
			// printw("%d", COLS);
		//------debug
		physics(dna);
		collisions(dna);
		// printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
		display(dna);
		// refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
		// getch();                // On attend que l'utilisateur appui sur une touche pour quitter
		move(5,5);
		printw("->      %f", dna->player.velocity.y);

		// if (dna.jump)
			// dna.player.velocity.y = dna.player.velocity.y + 800.0;
			// printw("fuck you");
		controller(dna);
	}

}

int main(void)
{
	t_dna dna;

	dna.jump = 0;

	WINDOW *w;

	init_dna(&dna);
	w = initscr();              // Initialise la structure WINDOW et autres paramètres
	// nodelay(w, TRUE);
	timeout(60);
	cbreak(); //getch() no block


	// create_ennemy(&dna, COLS - 80, 40);
	init_player(&dna);

	while (42)
	{
		main_game(&dna);
		while (42)
		{
			clear();
			move(25, COLS / 2);
			printw("GAME OVER");
			refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
		}
	}
    endwin();               // Restaure les paramètres par défaut du terminal

    return 0;
}
