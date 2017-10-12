/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchety <lchety@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 11:04:58 by lchety            #+#    #+#             */
/*   Updated: 2017/10/12 15:11:19 by lchety           ###   ########.fr       */
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

}

void	controller(t_dna *dna)
{
	int keycode;

	// nocbreak(); //getch() no block
	keycode = getch();
	// printw("keycode : %d\n", keycode);


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
}


int main(void)
{
	t_dna dna;

	WINDOW *w;

	init_dna(&dna);
	w = initscr();              // Initialise la structure WINDOW et autres paramètres
	// nodelay(w, TRUE);
	timeout(60);
	cbreak(); //getch() no block


	create_ennemy(&dna, COLS, 40);

	while (42)
	{
		clear();
		//------debug
			// move(0,0);
			// printw("%d", COLS);
		//------debug
		physics(&dna);
    	// printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
		display(&dna);
    	refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
    	// getch();                // On attend que l'utilisateur appui sur une touche pour quitter
		controller(&dna);
		// usleep(30000);
	}
    endwin();               // Restaure les paramètres par défaut du terminal

    return 0;
}
