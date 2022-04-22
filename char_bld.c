#include <libft/libft.h>
#include "char_bld.h"

t_char_bld	char_bld(void)
{
	t_char_bld	ch;

	ft_bzero(ch.c, 4);
	ch.bit = 0;
	ch.ready = 0;
	ch.byte = 0;
	ch.eos = 0;
	return (ch);
}

void	char_bld_append(t_char_bld *ch, int bit)
{
	if (bit)
		ch->c[ch->byte] |= (1 << ch->bit);
	++ch->bit;
	if (ch->bit == 8)
	{
		if (ch->c[ch->byte] == 0)
			ch->eos = 1;
		else
			ch->ready = 1;
		++ch->byte;
		ch->bit = 0;
	}
}
