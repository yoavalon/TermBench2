function updateGrid(grid) {
    let shape = [grid.length, grid[0].length];
    let newGrid = Array.from({ length: shape[0] }, () => Array(shape[1]).fill(0));
    for (let i = 0; i < shape[0]; i++) {
        for (let j = 0; j < shape[1]; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(shape[0], i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(shape[1], j + 2); y++) {
                    neighbors += grid[x][y];
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
    let size = 100;
    let grid = Array.from({ length: size }, () => Array(size).fill().map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid = updateGrid(grid);
    }
}

simulate();