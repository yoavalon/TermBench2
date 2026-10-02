import { zeros } from 'numeric';

function update_grid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const new_grid: number[][] = zeros([rows, cols]);

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let ni = Math.max(0, i - 1); ni < Math.min(rows, i + 2); ni++) {
                for (let nj = Math.max(0, j - 1); nj < Math.min(cols, j + 2); nj++) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1) {
                new_grid[i][j] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            } else {
                new_grid[i][j] = (neighbors === 3) ? 1 : 0;
            }
        }
    }
    return new_grid;
}

function main() {
    const grid_size = 10;
    const grid: number[][] = zeros([grid_size, grid_size]);
    grid[grid_size // 2][grid_size // 2] = 1;
    const steps = 50;

    for (let _ = 0; _ < steps; _++) {
        grid = update_grid(grid);
    }

    console.log(grid);
}

main();