/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:23:13 by hhecquet          #+#    #+#             */
/*   Updated: 2024/12/13 10:28:08 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/fdf.h"

static int get_3D_height(char *filename) {
    int fd;
    int height;
    char *line;

    height = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return -1; // Return error on file open failure

    line = get_next_line(fd);
    while (line) {
        height++; // Increment height for each line
        free(line); // Free the line after processing
        line = get_next_line(fd); // Read the next line
    }
    close(fd);
    return height; // Return total height
}

static int get_3D_width(char *filename) {
    int fd;
    int width;
    char *line;
    int i;

    width = 1; // Initialize width since lines have at least one value
    i = 0;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return -1; // Return error on file open failure

    line = get_next_line(fd);
    if (line) {
        while (line[i]) {
            if ((line[i] == ' ' && line[i - 1] != ' ') || !line[i + 1])
                width++;
            i++;
        }
        free(line); // Free line after processing
    }
    close(fd);
    return width; // Return total width
}

static t_point3D **alloc_map3D(int width, int height)
{
    int         i;
    t_point3D   **map3D;

    // Allocate memory for the rows of pointers (t_point3D*)
    map3D = (t_point3D **)malloc(sizeof(t_point3D *) * (height + 1));
    if (!map3D) // Check if map3D allocation failed
        return (NULL);

    // Loop to allocate memory for each row
    for (i = 0; i < height; i++)
    {
        map3D[i] = (t_point3D *)malloc(sizeof(t_point3D) * (width));
        if (!map3D[i]) // Check if row allocation failed
        {
            // Free any previously allocated rows to prevent memory leaks
            for (int j = 0; j < i; j++)
                free(map3D[j]);
            free(map3D);
            return (NULL);
        }
    }

    // Make the last pointer NULL for looping safety
    map3D[height] = NULL;
    return (map3D);
}

void parse_matrix(char *filename, t_point3D ***matrix)
{
    int     fd;
    int     i, j, k;
    char    *line;

    // Allocate the 3D map matrix
    *matrix = alloc_map3D(get_3D_width(filename), get_3D_height(filename));
    if (!*matrix)
    {
        ft_putstr_fd("Error: Failed to allocate memory for map3D.\n", 2);
        exit(EXIT_FAILURE);
    }

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        free_map3D(*matrix); // Free memory on failure
        exit(EXIT_FAILURE);
    }
    i = 0;
    while ((line = get_next_line(fd)))
    {
        j = 0;
        k = -1;
        while (line[++k])
        {
            if (line[k] >= '0' && line[k] <= '9' && (k == 0 || line[k - 1] == ' '))
                (*matrix)[i][j++].z = atoi(&line[k]);
        }
        free(line);
        i++;
    }
    close(fd);
}

void free_map3D(t_point3D **map3D)
{
    int i;

    if (!map3D)
        return;

    for (i = 0; map3D[i]; i++) // Free each allocated row
        free(map3D[i]);

    free(map3D); // Free the outer array
}