import * as np from 'numpy';

function update_grid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const new_grid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                    neighbors += grid[x][y];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    return new_grid;
}

function* simulate() {
    const grid_size = 50;
    const grid: number[][] = Array.from({ length: grid_size }, () => Array(grid_size).fill(0).map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid = update_grid(grid);
        yield grid;
    }
}

function main() {
    const sim = simulate();
    for (let _ = 0; _ < 1000; _++) {
        console.log(sim.next().value);
    }
}

main();