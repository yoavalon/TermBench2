function fluid_dynamics(grid) {
    const size = grid.length;
    const next_grid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                    neighbors += grid[x][y];
                }
            }
            next_grid[i][j] = neighbors > 4 ? 1 : 0;
        }
    }
    return fluid_dynamics(next_grid);
}

const grid = Array.from({ length: 10 }, () => Array(10).fill(0));
grid[5][5] = 1;
fluid_dynamics(grid);