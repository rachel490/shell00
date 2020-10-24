#include <unistd.h>

int	insert(int list, char *num)
{
	int array[4][4];
	int i;

	array[0] = line(*num+8, *num+12, list[4]);
	array[1] = line(*num+9, *num+13, list[5]);
	array[2] = line(*num+10, *num+14, list[6]);
	array[3] = line(*num+11, *num+15, list[7]);
	i = check(array, *num);
	if (i == 0)
		return (1);
	return (0);
}

void	make(int list, char *num, int i)
{
	while (list[4] < list[0])
	{
		list[5] = 0;
		while (list[5] < list[1])
		{
			list[6] = 0;
			while (list[7] < list[2])
			{
				list[7] = 0;
				while (list[7] < list[3])
				{
					list[7]++;
					i = insert(list, num);
					if (i == 1)
						return ;
				}
				list[6]++;
			}
			list[5]++;
		}
		list[4]++;
	}
	write(1, "Error", 5);
}

int	count(char x, char y)
{
	if ((x == 4 && y == 1) || (x == 1 && y == 4))
		return (1);
	if ((x == 3 && y == 2) || (x == 2 && y == 3))
		return (3);
	if (x == 2 && y == 2)
		return (4);
	if ((x == 2 && y == 1) || (x == 1 && y == 2))
		return (2);
}

int	main(int argc, char **argv)
{
	int a;
	int b;
	int c;
	int d;
	int i;
	char *num;
	int list[8];

	num = arvg[1];
	i = 0;
	a = count(*num+8, *num+12);
	b = count(*num+9, *num+13);
	c = count(*num+10, *num+14);
	d = count(*num+11, *num+15);
	list = {a, b, c, d, 0, 0, 0, 0};
	make(list, num, i)
	return (0);
}
