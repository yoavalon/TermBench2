function initializeGrid(size) {
    const grid = new Array(size);
    for (let i = 0; i < size; i++) {
        grid[i] = new Array(size).fill(0);
    }
    return grid;
}

function updateGrid(grid) {
    const newGrid = grid.map(row => row.slice());
    const rows = grid.length;
    const cols = grid[0].length;
    for (let i = 1; i < rows - 1; i++) {
        for (let j = 1; j < cols - 1; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    neighbors += grid[i + x][j + y];
                }
            }
            neighbors -= grid[i][j];
            if (neighbors === 3 || (grid[i][j] && neighbors === 2)) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = 0;
            }
        }
    }
    return newGrid;
}

function main() {
    const size = 50;
    let grid = initializeGrid(size);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();