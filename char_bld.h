#ifndef CHAR_BLD_H
# define CHAR_BLD_H

typedef struct s_char_bld
{
	char	c[4];
	int		bit;
	int		byte;
	int		ready;
	int		eos;
}	t_char_bld;

t_char_bld	char_bld(void);
void		char_bld_append(t_char_bld *ch, int bit);

#endif