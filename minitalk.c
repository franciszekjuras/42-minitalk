#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <libft/libft.h>

int	parse_pid(char *nstr, int *pid)
{
	int		err;

	err = 0;
	*pid = ft_strtonum(&nstr, 0, INT_MAX, &err);
	if (err || *nstr != '\0')
		return (-1);
	return (0);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	int		i;

	if (argc != 3 || parse_pid(argv[1], &server_pid) != 0)
		return (1);
	while (1)
	{
		i = -1;
		while (++i < 8)
		{
			if (*argv[2] & (1 << i))
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(5);
		}
		if (*argv[2] == '\0')
			break ;
		usleep(50);
		++argv[2];
	}
}
