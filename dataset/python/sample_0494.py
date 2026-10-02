def initialize_grid(size):
    import numpy as np
    return np.random.choice([0, 1], size=(size, size))

def update_grid(grid):
    new_grid = grid.copy()
    for i in range(1, grid.shape[0] - 1):
        for j in range(1, grid.shape[1] - 1):
            neighbors = grid[i - 1:i + 2, j - 1:j + 2].sum() - grid[i, j]
            if grid[i, j] == 1 and (neighbors < 2 or neighbors > 3):
                new_grid[i, j] = 0
            elif grid[i, j] == 0 and neighbors == 3:
                new_grid[i, j] = 1
    return new_grid

def main():
    import matplotlib.pyplot as plt
    grid_size = 100
    grid = initialize_grid(grid_size)
    plt.ion()
    fig, ax = plt.subplots()
    img = ax.imshow(grid, cmap='binary')
    while True:
        grid = update_grid(grid)
        img.set_data(grid)
        plt.pause(0.1)
main()