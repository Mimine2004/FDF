/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 11:39:51 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/13 13:23:00 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"    // MiniLibX library
#include <stdlib.h> // For malloc and free
#include <stdio.h>  // For perror and printf
#include <unistd.h> // For write
#include "../includes/fdf.h"
// Define your window dimensions
#define WIN_HEIGHT 1000
#define WIN_WIDTH 1350
// Define a structure to hold your program's data
typedef struct s_data {
    void *mlx;      // MiniLibX instance
    void *win;      // Window instance
    void *img;      // Image buffer
    char *addr;     // Data address for manipulating pixels
    int bpp;        // Bits per pixel (color depth)
    int line_length; // Number of bytes in one row of the image
    int endian;     // Byte order (little/big endian)
} t_data;

// Function to handle errors, clean resources, and exit gracefully
void handle_error(const char *msg, t_data *data)
{
    if (msg)
        write(2, msg, strlen(msg)); // Print error message to stderr
    if (data)
    {
        if (data->img) // Free the image if it exists
            mlx_destroy_image(data->mlx, data->img);
        if (data->win) // Destroy the window if it exists
            mlx_destroy_window(data->mlx, data->win);
        if (data->mlx) // Free the MiniLibX instance
            free(data->mlx);
    }
    exit(EXIT_FAILURE); // Exit with the failure status
}

// Hook function: Handles key presses (e.g., ESC to exit)
int key_handler(int keycode, t_data *data)
{
    if (keycode == 65307) // 'ESC' key on Linux
    {
        printf("ESC key pressed. Closing the application...\n");
        handle_error(NULL, data); // Clean up and exit
    }
    printf("Key pressed: %d\n", keycode); // Debug: Print keycode of pressed key
    return (0); // MiniLibX requires returning 0 in hook functions
}

// Function to set up and initialize an image buffer
void create_image(t_data *data)
{
    // Create a blank image
    data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
    if (!data->img)
        handle_error("Error: Image creation failed.\n", data);

    // Get access to the image's pixel data
    data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length, &data->endian);
    if (!data->addr)
        handle_error("Error: Failed to get image data address.\n", data);
}

// Function to handle the MiniLibX main loop's "close window" event
int close_window(t_data *data)
{
    printf("Window close event triggered. Exiting the application...\n");
    handle_error(NULL, data); // Clean up and exit
    return (0); // MiniLibX requires returning 0 in event hooks
}
/* void test_draw(t_mlx *mlx)
{
    // Example of drawing a simple horizontal line
    int x;
    int y = 300; // Middle of the window vertically

    for (x = 100; x < 700; x++)  // Draw horizontally across the screen
    {
        mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xFFFFFF);  // White color
    }
} */
// Main function - Entry point for your program
int main(void)
{
    t_data data; // Create a struct to hold your application's state

	void *mlx_ptr = mlx_init();
	if (!mlx_ptr) {
        fprintf(stderr, "Error: MiniLibX initialization failed.\n");
        return 1;
    }
	void *win_ptr = mlx_new_window(mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Test Draw Line");
	if (!win_ptr) {
        fprintf(stderr, "Error: Window creation failed.\n");
        return 1;
	}
	
	
    // Initialize the MiniLibX instance
    data.mlx = mlx_init();
    if (!data.mlx)
        handle_error("Error: MiniLibX initialization failed.\n", &data);

    // Create a window
    data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "FdF - 42 Project");
    if (!data.win)
        handle_error("Error: Window creation failed.\n", &data);

    // Create an empty image (optional, needed for rendering graphics/pixels)
    create_image(&data);
	mlx_init_background(mlx_ptr,win_ptr, WIN_WIDTH, WIN_HEIGHT, 0x008AD5);

    // Set up event handlers
    mlx_key_hook(data.win, key_handler, &data);       // Key press event handler
    mlx_hook(data.win, 17, 0, close_window, &data);  // Handle window close (x button)

    // Enter the MiniLibX rendering loop

	mlx_loop(data.mlx);

    return (0); // Technically unreachable due to mlx_loop()
}