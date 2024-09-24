#include "so_long.h"
#include "MinilibX/mlx.h"

int main(int ac , char **av)
{
    void    *mlx_ptr;
    void    *mlx_window;

    mlx_ptr = mlx_init();
    if(!mlx_ptr)
        return (1);
    mlx_window = mlx_new_window(mlx_ptr, 600, 400, "so_long");
    if(!mlx_window)
        return (free(mlx_ptr), 1);
    mlx_loop(mlx_ptr);
    return(0);
}