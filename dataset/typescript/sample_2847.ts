import * as np from 'numpy';

function update_grid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const new_grid = np.copy(grid);
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            const neighbors = grid[i][(j - 1 + cols) % cols] + grid[i][(j + 1) % cols] + grid[(i - 1 + rows) % rows][j] + grid[(i + 1) % rows][j] + grid[(i - 1 + rows) % rows][(j - 1 + cols) % cols] + grid[(i - 1 + rows) % rows][(j + 1) % cols] + grid[(i + 1) % rows][(j - 1 + cols) % cols] + grid[(i + 1) % rows][(j + 1) % cols];
            if (grid[i][j] === 1) {
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                }
            } else if (neighbors === 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

function main() {
    const grid_size = 10;
    let grid = np.random.choice([0, 1], { size: [grid_size, grid_size] });
    while (true) {
        grid = update_grid(grid);
        console.log(grid);
        console.log('--------------------');
    }
}

main();