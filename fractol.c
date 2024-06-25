#include "fractol.h"


t_params parser(int argc, char **argv){
	t_params params;
	int i;

	params.fract = -1;
	params.real = 0;
	params.imag = 0;
	params.red = 3;
	params.green = 6;
	params.blue = 5;
	if (!ft_strcmp("mandelbroth", argv[1]) || !ft_strcmp("M", argv[1]))
		params.fract = 0;
	else if ((!ft_strcmp("julia", argv[1]) || !ft_strcmp("J", argv[1])) && argc > 2)
	{
		params.fract = 1;
		params.real = ft_atof(argv[2]);
		params.imag = ft_atof(argv[3]);
	}
	else if (!ft_strcmp("tricorn", argv[1]) || !ft_strcmp("T", argv[1]))
		params.fract = 2;
	if (params.fract == 1)
		i = 4;
	else
		i = 2;
	while (argv[i])
	{
		if (!ft_strcmp("red", argv[i]) && argv[i + 1])
			params.red = ft_atoi(argv[i + 1]);
		else if (!ft_strcmp("blue", argv[i]) && argv[i + 1])
			params.blue = ft_atoi(argv[i + 1]);
		else if (!ft_strcmp("green", argv[i]) && argv[i + 1])
			params.green = ft_atoi(argv[i + 1]);
		else 
			params.fract = -1;
		i++;
	}
	return (params);
}



int main(int argc, char **argv)
{
	t_params param = parser(argc, argv);
    t_vars vars;

	if (param.fract != -1){
		vars.param = param;
    	vars.mlx = mlx_init();
    	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fractol");
		vars.x = 0;
		vars.y = 0;
		vars.zoom = 1.0;
		t_image img;
		img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
		img.addr = mlx_get_data_addr(img.img, &img.bbp, &img.ll, &img.endian);
	
		vars.img = img;
		vars.screen.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
		vars.screen.addr = mlx_get_data_addr(vars.screen.img, &vars.screen.bbp, &vars.screen.ll, &vars.screen.endian);
	
		if (param.fract == 0)
			fractal_mandelbroth(&vars.screen, -2.0, 2.0, ITER, vars.x, vars.y, &vars);
		else if (param.fract == 1)
			fractal_julia(&vars.screen, param.real, param.imag, -2.0, 2.0, ITER, vars.x, vars.y, &vars);
		else if (param.fract == 2)
			fractal_tricorn(&vars.screen, -2.0, 2.0, ITER, vars.x, vars.y, &vars);
		mlx_put_image_to_window(vars.mlx, vars.win, vars.screen.img, 0, 0);
		mlx_hook(vars.win, 2, 1L << 0, key_hook, &vars);
		mlx_hook(vars.win, 17, 0, close_window, &vars);
		mlx_mouse_hook(vars.win, mouse_hook, &vars);
    	mlx_loop(vars.mlx);
	}
	else
		printf("Usage: ./fractol mandelbroth/M/julia/J/tricorn/T/newton/N. For julia enter real and imaginary parts after. You can change the rgb steps by $color $step_int");
    return 0;
}
