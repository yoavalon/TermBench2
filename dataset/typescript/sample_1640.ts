import * as np from 'numpy';

function update_grid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const new_grid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
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
                if (neighbors < 2 || neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else if (neighbors === 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

function main() {
    const size = 50;
    const grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0).map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid = update_grid(grid);
    }
}

main();