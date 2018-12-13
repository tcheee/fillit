
int		get_size(nb)
{
	int i;

	i = 2;
	while (i * i < nb * 4)
		i++;
	return (i);
}
