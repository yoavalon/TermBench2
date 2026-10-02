import { randomInt } from 'crypto';

function initialize_grid(size: number): number[][] {
    return Array.from({ length: size }, () => Array.from({ length: size }, () => randomInt(2)));
}

function update_grid(grid: number[][]): number[][] {
    const size = grid.length;
    const new_grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let x of [-1, 0, 1]) {
                for (let y of [-1, 0, 1]) {
                    if (x === 0 && y === 0) continue;
                    let ni = i + x;
                    let nj = j + y;
                    if (ni < 0) ni += size;
                    else if (ni >= size) ni -= size;
                    if (nj < 0) nj += size;
                    else if (nj >= size) nj -= size;
                    neighbors += grid[ni][nj];
                }
            }
            if (grid[i][j] === 1 && (neighbors === 2 || neighbors === 3)) {
                new_grid[i][j] = 1;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

function main() {
    const grid_size = 50;
    let grid = initialize_grid(grid_size);
    while (true) {
        grid = update_grid(grid);
    }
}

main();