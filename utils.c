
double map(double var, double min, double max, double map_min, double map_max){
	double scale = (map_max - map_min)/(max - min);
	double ret = (var - min) * scale + map_min;
	return (ret);
}

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	return (0);
}

float ft_atof(const char *str)
{
    float nb = 0;
    float fraction = 0;
    float divisor = 10;
    int mult = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            mult = -1;
        str++;
    }
    while (*str && *str >= '0' && *str <= '9')
        nb = nb * 10 + (*str++ - '0');
    if (*str == '.')
        str++;
    while (*str && *str >= '0' && *str <= '9')
    {
        fraction += (*str++ - '0') / divisor;
        divisor *= 10;
    }
    return mult * (nb + fraction);
}

int zigzag_map(int var, int min, int max){
	int range = max - min;
	int cycles = (var - min) / range;
	int rem = (var - min) % range;
	if (cycles % 2 == 0)
		return (min + rem);
	else
		return (max - rem);
}
