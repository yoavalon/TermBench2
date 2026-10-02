import * as numpy from 'numpy';

function updateGrid(grid: number[][]): number[][] {
    const newGrid = numpy.zeros_like(grid);
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[i].length - 1; j++) {
            const neighbors = numpy.sum(grid.slice(i - 1, i + 2).map(row => row.slice(j - 1, j + 2))) - grid[i][j];
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
    const gridSize = 50;
    const grid = numpy.random.choice([0, 1], [gridSize, gridSize]);
    while (true) {
        grid = updateGrid(grid);
    }
}

simulate();