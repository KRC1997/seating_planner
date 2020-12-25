# ifndef GRAPHICS_HPP
# define GRAPHICS_HPP

# define XRES 120		//remains constant
# define YRES 900		//may be variable

int Menu (char **arr, int rows);
int Menu (char **arr, int rows, char *header);
int Menu (char **arr, int rows, char *header, char *footer);

# endif