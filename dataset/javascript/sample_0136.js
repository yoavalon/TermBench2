function initializeGrid(size) {
    let grid = new Array(size);
    for (let i = 0; i < size; i++) {
        grid[i] = new Array(size).fill(0);
    }
    return grid;
}

function updateGrid(grid) {
    let newGrid = JSON.parse(JSON.stringify(grid));
    let rows = grid.length;
    let cols = grid[0].length;
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let ni = Math.max(0, i - 1); ni < Math.min(rows, i + 2); ni++) {
                for (let nj = Math.max(0, j - 1); nj < Math.min(cols, j + 2); nj++) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            }
        }
    }
    return newGrid;
}

function main() {
    let gridSize = 50;
    let iterations = 100;
    let grid = initializeGrid(gridSize);
    for (let _ = 0; _ < iterations; _++) {
        grid = updateGrid(grid);
    }
    console.log(grid);
}

main();