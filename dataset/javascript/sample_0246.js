const { zeros } = require('ndarray');

function initializeGrid(size) {
    let grid = zeros([size, size], 'int32');
    grid[size // 2][size // 2] = 1;
    return grid;
}

function applyBoundaryConditions(grid) {
    let size = grid.shape[0];
    for (let i = 0; i < size; i++) {
        grid.get(0, i, 0);
        grid.set(0, i, 0);
        grid.set(size - 1, i, 0);
        grid.set(i, 0, 0);
        grid.set(i, size - 1, 0);
    }
}

function updateGrid(grid) {
    let newGrid = grid.clone();
    let size = grid.shape[0];
    for (let i = 1; i < size - 1; i++) {
        for (let j = 1; j < size - 1; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    neighbors += grid.get(i + di, j + dj);
                }
            }
            neighbors -= grid.get(i, j);
            if (grid.get(i, j) === 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid.set(i, j, 0);
                }
            } else if (neighbors === 3) {
                newGrid.set(i, j, 1);
            }
        }
    }
    return newGrid;
}

function simulate(steps) {
    let size = 50;
    let grid = initializeGrid(size);
    applyBoundaryConditions(grid);
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid);
        applyBoundaryConditions(grid);
    }
    return grid;
}

function main() {
    let steps = 100;
    let result = simulate(steps);
    console.log(result);
}

main();