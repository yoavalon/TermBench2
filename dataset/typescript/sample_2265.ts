import * as np from 'numpy';

function updateGrid(grid: number[][], size: number): number[][] {
    const newGrid: number[][] = np.zerosLike(grid);
    for (let i = 1; i < size - 1; i++) {
        for (let j = 1; j < size - 1; j++) {
            const neighbors = grid.slice(i - 1, i + 2).map(row => row.slice(j - 1, j + 2)).flat();
            const neighborsSum = np.sum(neighbors) - grid[i][j];
            if (grid[i][j] === 0 && neighborsSum > 2) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] === 1 && (neighborsSum < 2 || neighborsSum > 3)) {
                newGrid[i][j] = 0;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    return newGrid;
}

function main() {
    const size = 50;
    const grid: number[][] = np.zeros([size, size]);
    grid[size // 2][size // 2] = 1;
    while (true) {
        grid = updateGrid(grid, size);
    }
}

main();