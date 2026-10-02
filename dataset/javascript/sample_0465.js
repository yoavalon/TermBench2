function initializeGrid(size) {
    let grid = Array.from({ length: size }, () => Array(size).fill(0));
    grid[Math.floor(size / 2)][Math.floor(size / 2)] = 1;
    return grid;
}

function updateGrid(grid) {
    let newGrid = Array.from({ length: grid.length }, () => Array(grid.length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid.length; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(grid.length, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            if (neighbors === 3 || (grid[i][j] === 1 && neighbors === 2)) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    let gridSize = 10;
    let grid = initializeGrid(gridSize);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();