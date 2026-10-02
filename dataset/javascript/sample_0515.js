const { randomInt } = require('crypto');

function initializeGrid(size) {
    return Array.from({ length: size }, () => Array.from({ length: size }, () => randomInt(2)));
}

function updateGrid(grid) {
    const size = grid.length;
    const newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x === 0 && y === 0) continue;
                    let ni = (i + x + size) % size;
                    let nj = (j + y + size) % size;
                    neighbors += grid[ni][nj];
                }
            }
            if (grid[i][j] === 1 && (neighbors === 2 || neighbors === 3)) {
                newGrid[i][j] = 1;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    const gridSize = 50;
    let grid = initializeGrid(gridSize);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();