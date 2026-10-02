function initializeGrid(size) {
    let grid = Array.from({ length: size }, () => Array(size).fill(0));
    grid[Math.floor(size / 2)][Math.floor(size / 2)] = 1;
    return grid;
}

function updateGrid(grid) {
    let size = grid.length;
    let newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                    neighbors += grid[x][y];
                }
            }
            if (neighbors === 3 || (grid[i][j] && neighbors === 2)) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    let size = 10;
    let grid = initializeGrid(size);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();