function updateGrid(grid) {
    const newGrid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[0].length - 1; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    neighbors += grid[i + di][j + dj];
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
    const gridSize = 50;
    const grid = Array.from({ length: gridSize }, () => Array(gridSize).fill(0).map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid = updateGrid(grid);
    }
}

simulate();