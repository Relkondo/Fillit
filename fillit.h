/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:41:24 by jubeal            #+#    #+#             */
/*   Updated: 2018/11/29 18:29:35 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct				s_pieces
{
	unsigned short			*piece;
	struct s_pieces			*next;
}							t_pieces;

t_pieces					*create_lstlink(t_pieces **link);
void						line_convert(t_pieces **curr, char *line,
								int which);
void						initialize_pieces(t_pieces **head);
unsigned short				*ft_solve(t_pieces *bitch, unsigned short *map,
								int sq_size);
int							ft_move_piece(t_pieces *bitch, int sq_size);
void						ft_reset_piece(t_pieces *bitch, int sq_size);
int							errors(int type);
void						affichage(t_pieces *head, int taille_map);

#endif
