/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:27:17 by jjaen-mo          #+#    #+#             */
/*   Updated: 2023/06/30 13:49:18 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "../MLX42/include/MLX42/MLX42.h"
# include "../include/libs/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/**
 * @brief Structure used to store the map and its height and width
 * 
 */
typedef struct s_map
{
	char		**matrix;
	int			width;
	int			height;
}				t_map;

/**
 * @brief Main Structure. Stores EVERYTHING
 * 
 */
typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*character;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	**colls;
	mlx_image_t	*exit;
	mlx_image_t	**enemies;
	t_map		map;
	int			playerposx;
	int			playerposy;
	int			coll_count;
	int			max_colls;
	int			enem_count;
	int			steps;
}				t_data;
/**
 * @brief Iniciate every data value at 0 or NULL
 * 
 * @param data The data structure
 * @return t_data The data structure iniciated
 */
t_data			ft_init_data(t_data data);
/**
 * @brief Reads the file passed as argument
 * and returns a string with its content
 * 
 * @param file The route to the file
 * @return char* The string with the content
 */
char			*ft_read_file(char *file);
/**
 * @brief Checks if the file extension is .ber
 * 
 * @param file The route to the file
 */
void			ft_file_extension(char *file);
/**
 * @brief Checks if the map is valid
 * 
 * @param map The map string (file read)
 */
void			ft_parse_map(char *map);
/**
 * @brief Displays a custom error for each case
 * of the map and closes the program
 * 
 * @param type The type of error to display
 */
void			ft_map_error(char type);
/**
 * @brief Gets the height and width of the map
 * and stores in the main data structure
 * 
 * @param map The map string (file read)
 * @param data The main data structure
 * @return t_data 
 */
t_data			ft_get_hw(char *map, t_data data);
/**
 * @brief Creates a matrix with the map string
 * 
 * @param map_arr The map string (file read)
 * @param height The height of the map (number of rows)
 * @param width The width of the map (number of columns)
 * @return char** The matrix created
 */
char			**ft_create_map(char *map_arr, int height, int width);
/**
 * @brief Checks if every row of the map has the same width
 * 
 * @param data The main data structure
 * @param width The width of the map
 * @param height The height of the map
 */
void			ft_equal_width(t_data data, int width, int height);
/**
 * @brief Frees the map matrix
 * 
 * @param map The map to free
 * @return char** The map freed (NULL)
 */
char			**ft_free(char **map);
/**
 * @brief Checks if the map is surrounded by walls
 * 
 * @param map The map matrix
 * @param width The width of the map
 * @param height The height of the map
 */
void			ft_check_walls(char **map, int width, int height);
/**
 * @brief Opens the window and displays the game
 * 
 * @param data The main data structure
 * @param file_read The map string (file read)
 * @return int Returns the success of the window creation
 */
int				ft_create_window(t_data data, char *file_read);
/**
 * @brief Iniciates the window, loads the textures and gets
 * the max number of collectibles (and enemies if its a bonus map)
 * 
 * @param data The main data structure
 * @return t_data The main data structure with the changes made
 */
t_data			ft_iniciate(t_data data);
/**
 * @brief Get the max number of C characters in the map
 * 
 * @param map The map matrix
 * @param c The character to count
 * @return int The number of C characters
 */
int				ft_get_max(char **map, char c);
/**
 * @brief Creates the textures, changes them to images and stores
 * them in the main data structure
 * 
 * @param data The main data structure
 * @return t_data The main data tructure with the textures loaded
 */
t_data			ft_create_textures(t_data data);
/**
 * @brief Stores the collectibles matrix in memory
 * 
 * @param data The main data structure
 * @return t_data The main data structure modified
 */
t_data			ft_malloc_colls(t_data data);
/**
 * @brief Loads the enemies textures if needed
 * 
 * @param data The main data structure
 * @return t_data The main data structure modified
 */
t_data			ft_enemy_texture(t_data data);
/**
 * @brief Stores the enemies matrix in memory
 * 
 * @param data The main data structure
 * @return t_data The main data structure modified
 */
t_data			ft_malloc_enemies(t_data data);
/**
 * @brief Loads the collectibles textures to the window
 * 
 * @param data The main data structure
 * @return t_data The data structure modified
 */
t_data			ft_collectible_texture(t_data data);
/**
 * @brief Draws the map in the window, using the map and
 * the loaded images
 * 
 * @param data The main data structure
 * @return t_data The main data structure with the map drawn
 */
t_data			ft_gen_map(t_data data);
/**
 * @brief Draws the collectibles into the window
 * 
 * @param height The Y position of the collectible in the map
 * @param width The X position of the collectible in the map
 * @param data The main data structure
 */
void			ft_collectible(int height, int width, t_data data);
/**
 * @brief Draws the exit image into the window, above a floor
 * 
 * @param height The Y position of the exit in the map
 * @param width The X position of the exit int the map
 * @param data The main data structure
 */
void			ft_exit_img(int height, int width, t_data data);
/**
 * @brief Draws the enemies into the window
 * 
 * @param data The main data structure
 * @param width The X position of the enemy in the map
 * @param height The Y position of the enemy in the map
 */
void			ft_enemies(t_data data, int width, int height);
/**
 * @brief Searches the position of the player, stores it, and draws 
 * the player
 * 
 * @param data The main data structure
 * @return t_data The main data structure with the player drawn
 */
t_data			ft_gen_player(t_data data);
/**
 * @brief Draws the player into the window, above a floor
 * 
 * @param height The Y position of the player in the map
 * @param width The X position of the player in the map
 * @param data The main data structure
 * @return t_data The main data structure with the player drawn
 */
t_data			ft_player(int height, int width, t_data data);
/**
 * @brief Checks if the map is solvable
 * 
 * @param data The main data structure
 * @param x The player X position
 * @param y The player Y position
 * @param trues A pointer to a home-made boolean
 * @return int The home-made boolean
 */
int				ft_check_solvable(t_data *data, int x, int y, int *trues);
/**
 * @brief Closes the window, freeing the memory stored
 * 
 * @param data The main data structure
 */
void			ft_close_window(void *data);
/**
 * @brief Is the hook used to move the player. Checks if next movement
 * is possible and if it is, moves the player. Also is the one that checks
 * if ESC key is pressed and closes the window
 * 
 * @param keydata The structure that stores the key pressed
 * @param data A pointer to the main data structure
 */
void			ft_movement(mlx_key_data_t keydata, void *data);
/**
 * @brief Checks if the player next position is viable (Not a wall)
 * 
 * @param height The Y position of the player in the map
 * @param width The X position of the player in the map
 * @param key The key pressed
 * @param map The map matrix
 * @return int A home-made boolean (true(1) or false(0))
 */
int				ft_next_pos(int32_t height, int32_t width, char key,
					char **map);
/**
 * @brief Moves the player position and draws the steps in the window
 * 
 * @param data A pointer to the main data structure
 * @param posx A pointer to the x position of the player
 * @param posy A pointer to the y position of the player
 * @param key The key pressed
 */
void			ft_add_step(t_data *data, int32_t *posx, int32_t *posy,
					char key);
/**
 * @brief Changes the sprite of the player, making the animations
 * 
 * @param data A pointer to the main data structure
 * @param key The key pressed
 */
void			ft_change_sprite(t_data *data, char key);
/**
 * @brief Draws the steps into the window
 * 
 * @param data A pointer to the main data structure
 * @param str The string storing the steps
 * @param steps The image of the steps
 * @return mlx_image_t* The image drawn
 */
mlx_image_t		*ft_put_steps(t_data *data, char *str, mlx_image_t *steps);
/**
 * @brief The hook used to display the exit image and to close the window
 * if the player touches the exit, once every collectible is picked up
 * 
 * @param data The main data structure
 */
void			ft_open_exit(t_data data);
/**
 * @brief Changes the image of the exit from nothing to the actual exit
 * 
 * @param data The main data structure
 */
void			ft_change_exit(void *data);
/**
 * @brief Adds a collectible to the count, once the player touches it
 * 
 * @param data A pointer to the main data structure
 */
void			ft_add_coll(void *data);
/**
 * @brief Checks if the player touches an enemy, and if it does,
 * closes the window displaying "You lose!"
 * 
 * @param data 
 */
void			ft_enemy_touch(t_data data);
/**
 * @brief Checks if the program is leaking memory
 * 

void			ft_leaks(void);*/

#endif