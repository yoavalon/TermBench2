import * as math from 'mathjs';

function initialize_grid(size: number): number[][] {
    const grid: number[][] = [];
    for (let i = 0; i < size; i++) {
        const row: number[] = [];
        for (let j = 0; j < size; j++) {
            row.push(Math.floor(Math.random() * 2));
        }
        grid.push(row);
    }
    return grid;
}

function evolve(grid: number[][]): number[][] {
    const size = grid.length;
    const next_grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    const ni = (i + di + size) % size;
                    const nj = (j + dj + size) % size;
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                next_grid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                next_grid[i][j] = 1;
            } else {
                next_grid[i][j] = grid[i][j];
            }
        }
    }
    return next_grid;
}

function main() {
    const grid_size = 100;
    let grid = initialize_grid(grid_size);
    while (true) {
        grid = evolve(grid);
    }
}

main();