const { random, zeros } = require('mathjs');

function updateGrid(grid: number[][]): number[][] {
    const shape = [grid.length, grid[0].length];
    const newGrid = zeros(shape[0], shape[1]) as number[][];
    for (let i = 0; i < shape[0]; i++) {
        for (let j = 0; j < shape[1]; j++) {
            let neighbors = 0;
            for (let ni = Math.max(0, i - 1); ni < Math.min(shape[0], i + 2); ni++) {
                for (let nj = Math.max(0, j - 1); nj < Math.min(shape[1], j + 2); nj++) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    return newGrid;
}

function simulate() {
    const size = 100;
    const grid = Array.from({ length: size }, () => Array(size).fill(0).map(() => Math.floor(random() * 2)));
    while (true) {
        grid = updateGrid(grid);
    }
}

simulate();