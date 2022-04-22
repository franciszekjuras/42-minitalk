#include <unistd.h>
#include <signal.h>
#include <libft/libft.h>
#include "char_bld.h"

volatile int	*buffer(void)
{
	static volatile int	last = -1;

	return (&last);
}

void	sighand(int sig)
{
	if (sig == SIGUSR1)
		*buffer() = 0;
	else if (sig == SIGUSR2)
		*buffer() = 1;
}

void	flush_char_bld(t_char_bld *ch)
{
	if (ch->ready > 0)
	{
		write(1, ch->c, ch->byte);
	}
	*ch = char_bld();
}

int	main(void)
{
	t_char_bld	chbld;

	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	signal(SIGUSR1, sighand);
	signal(SIGUSR2, sighand);
	while (1)
	{
		chbld = char_bld();
		while (!chbld.eos)
		{
			sleep(1000);
			if (*buffer() >= 0)
				char_bld_append(&chbld, *buffer());
			*buffer() = -1;
			if (chbld.ready)
				flush_char_bld(&chbld);
		}
		ft_putendl_fd("", 1);
	}
}
