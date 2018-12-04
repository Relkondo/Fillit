/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubeal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 15:41:24 by jubeal            #+#    #+#             */
/*   Updated: 2018/12/04 22:01:01 by scoron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"

typedef struct			s_pieces
{
	unsigned short		*piece;
	struct s_pieces		*next;
}						t_pieces;

typedef	struct			s_fibox
{
	int					n;
	int					sq_size;
	int					h_max;
	int					full_line;
	int					nb_holes;
	int					sz_hole;
	int					lmin;
	int					lmax;
	int					pos;
}						t_fibox;

t_pieces				*create_lstlink(t_pieces **link);
void					line_convert(t_pieces **curr, char *line,
						int which);
void					initialize_pieces(t_pieces **head);
int						ft_solve_init(t_pieces *bitch,
						unsigned short **map, t_fibox *toolbox);
int						check_line(char *str, int type);
int						check_file(int fd, t_pieces **head);
int						check_pieces(t_pieces *bitch);
int						ft_move_piece(t_pieces *bitch, int sq_size);
void					ft_reset_piece(t_pieces *bitch, int sq_size);
int						errors(int type);
void					affichage(t_pieces *head, int taille_map);
void					scan_holes(t_fibox *toolbox,
						t_pieces *bitch, unsigned short **map);
int						ft_checkhole_init(t_fibox *toolbox,
						unsigned short **map, int line, int pos);
int						ft_checkhole_down(t_fibox *toolbox,
						unsigned short **map, int line, int pos);
int						ft_checkhole_up(t_fibox *toolbox,
						unsigned short **map, int line, int pos);
int						ft_checkhole_left(t_fibox *toolbox,
						unsigned short **map, int line, int pos);
int						ft_checkhole_right(t_fibox *toolbox,
						unsigned short **map, int line, int pos);
int						ft_send_up(t_fibox *toolbox,
						unsigned short **map, int line, int pos);
int						ft_send_down(t_fibox *toolbox,
						unsigned short **map, int line, int pos);
int						ft_send_right(t_fibox *toolbox,
						unsigned short **map, int line, int pos);
int						ft_send_left(t_fibox *toolbox,
						unsigned short **map, int line, int pos);

#endif
