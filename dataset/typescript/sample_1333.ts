import * as np from 'numpy';

function updateGrid(grid: number[][]): number[][] {
    const newGrid = np.copy(grid);
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[i].length - 1; j++) {
            const neighbors = np.sum(grid.slice(i - 1, i + 2).map(row => row.slice(j - 1, j + 2))) - grid[i][j];
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (!grid[i][j] && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function simulate(grid: number[][], steps: number): number[][] {
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid);
    }
    return grid;
}

function main() {
    const size = 50;
    const grid: number[][] = np.zeros([size, size], { dtype: 'int' });
    grid.slice(20, 25).forEach((row, i) => row.slice(20, 25).forEach((_, j) => grid[i + 20][j + 20] = Math.floor(Math.random() * 2)));
    const finalGrid = simulate(grid, 100);
    console.log(finalGrid);
}

main();