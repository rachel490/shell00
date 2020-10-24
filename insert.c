#include <unistd.h>

int	same_1(int a, int b, char ch)
{
	if ((a == 4 && b == 1) && (ch == "1234"))
		return (0);
	if ((a == 1 && b == 4) && (ch == "4321"))
		return (0);
	if ((a == 3 && a == 2) && (ch == "1243" || ch == "1342" || ch == "2341"))
		return (0);
	if ((a == 2 && a == 3) && (ch == "3421" || ch == "2431" || ch == "1432"))
		return (0);
	if ((a == 2 && b == 2) && (ch == "1423" || ch == "2413" || ch == "3241" || ch == "3142"))
		return (0);
	if ((a == 2 && b == 1) && (ch == "3214" || ch == "3124"))
		return (0);
	if ((a == 1 && b == 2) && (ch == "4123" || ch == "4213"))
		return (0);
	return (1);
}

int	same(char ch, char *num)
{
	int a;
	int b;
	int c;

	i = 0;
	a = *num;
	b = *num+4;
	i += same_1(a, b, ch[0]);
	a = *num+1;
	b = *num+5;
	i += same_1(a, b, ch[1]);
	a = *num+2;
	b = *num+6;
	i += same_1(a, b, ch[2]);
	a = *num+3;
	b = *num+7;
	i += same_1(a, b, ch[3]);
	return (i);
}

void	pr(char array)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < 4)
	{
		while (y < 4)
		{
			write(1, &array[x][y], 1);
			y++;
		}
		write(1, "\n", 1);
		x++;
	}
}

int	check(char array, char *num)
{
	int ch[4][4];
	int i;
	int a;

	i = 0;
	a = 0;
	while (i < 4)
	{
		ch[i] = array[0][i] + array[1][i] + array[2][i] + array[3][i];
		i++;
	}
	a = same(ch, num);
	if (a == 0)
	{
		pr(array);
		return (1);
	}
	return (0);
}

char	line(char x, char y, int A)
{
	if (x == 4 && y == 1)
		return ("1234");
	if (x == 1 && y == 4)
		return ("4321");
	if (x == 3 && x == 2)
		A != 2 ? A == 0 ? return ("1243") : return ("1342") : return ("2341");
	if (x == 2 && x == 3)
		A != 2 ? A == 0 ? return ("3421") : return ("2431") : return ("1432");
	if (x == 2 && y == 2)
		A < 2 ? A == 0 ? return ("1423") : return ("2413") : A == 2 ? return ("3241") : return ("3142");
	if (x == 2 && y == 1)
		A == 0 ? return ("3214") : return ("3124");
	if (x == 1 && y == 2)
		A == 0 ? return ("4123") : return ("4213");
}