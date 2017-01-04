#include "mlx.h"
#include "libft.h"
#include <sys/types.h>		//Les Headers nécéssaire
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#define SIZE 42

//============================================================================================
//********************************************************************************************
//============================================================================================

void    ft_putchar(char c)      //en p1, le caractere a afficher
{
    write(1, &c, 1);            //p1 = sortie standard, p2 = le caractere, p3 = la taille.
}

void	ft_putstr(char *str)		//en p1, un tableau
{
	int index;

	index = 0;
	while (str[index] != '\0')		//Tant que le contenu de la case du tsableau n'est pas \0
	{
		ft_putchar(str[index]);		//On affiche le caractere correspondant a la case 
		index++;
	}
}

void    ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);

	ft_putchar((nb % 10) + '0');

}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		signe;

	i = 0;
	signe = 1;
	nb = 0;
	while (str[i] < 33 && str[i] > 0)
		i++;
	if (str[i] == '-')
	{
		signe = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	return ((int)(nb * signe));
}

static int		ft_count(char const *s, char c)
{
	int i;
	int	nb;

	i = 0;
	nb = 0;
	if (!s || !c)
		return (0);
	while (s[i])
	{
		nb++;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

static char		*ft_cp(char const *s, char c, int *i)
{
	int		a;
	char	*s2;

	a = 0;
	s2 = (char *)malloc(sizeof(s2) * (ft_strlen(s)) + 1);
	if (!s2)
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		s2[a] = s[*i];
		a++;
		*i += 1;
	}
	s2[a] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (s2);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		nb;
	char	**s2;

	i = 0;
	j = 0;
	nb = ft_count(s, c);
	if (!s || !c)
		return (NULL);
	s2 = (char **)malloc(sizeof(s) * (nb + 1));
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		while (j < nb && s[i])
		{
			s2[j] = ft_cp(s, c, &i);
			j++;
		}
		s2[j] = NULL;
	}
	return (s2);
}

void ft_printabint(int *tabint, char *phrase, char *NomTest, int taille)
{
	int i;

	i = 0;
	ft_putstr(NomTest);
	ft_putchar('\n');
	while (i < taille)
	{
		ft_putstr(phrase);
		ft_putnbr(tabint[i]);
		ft_putchar('\n');
		i++;
	}
}
	
//A TESTER, MARCHE PAS SUR TOUTES LES MAPS
int 	*ft_count_xy(char *buf, int fd, int *nblc)
{
	int i;
	int end;

	while ((end = read(fd, buf, SIZE)))
	{
		buf[end] = '\0';
		i = 0;
		while (buf[i])
		{
			while (buf[i] && buf[i] == ' ')
				i++;
			while (buf[i] && buf[i] != ' ' && buf[i] != '\n')
				i++;
			while (buf[i] && buf[i] == ' ')
				i++;
			if (buf[i] == '\n')
			{
				i++;
				nblc[1]++;
			}
			nblc[0]++;
		}
	}
	nblc[0] = nblc[0]/nblc[1];
	return (nblc);
}

int main(int argc, char **argv)
{
	int 	*countxy;
	char	buf[SIZE + 1];
	int		fd;
	int 	*nblc; 		//nblc[0] = Nombre de caracteres && nblc[1] = Nombre de lignes

	if (argc == 12)
		argc = 12;
	nblc = (int *)malloc(sizeof(int) * 2);
	nblc[0] = 0;
	nblc[1] = 0;
	fd = open(argv[1], O_RDONLY);
	countxy = ft_count_xy(buf, fd, nblc);
	ft_printabint(nblc, "nblc = ", "Test_nblc", 2);
	return (0);
}