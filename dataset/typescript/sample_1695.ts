import * as _ from 'lodash';

function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = _.times(rows, () => _.times(cols, () => 0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            const neighbors = _.sum(_.flatten(grid.slice(Math.max(0, i - 1), Math.min(rows, i + 2))
                .map(row => row.slice(Math.max(0, j - 1), Math.min(cols, j + 2))))) - grid[i][j];
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

function runSimulation() {
    const gridSize = 50;
    const grid = _.times(gridSize, () => _.times(gridSize, () => _.random(0, 1)));
    while (true) {
        grid = updateGrid(grid);
    }
}

runSimulation();