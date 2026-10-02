const { random } = require('mathjs');

function updateGrid(grid) {
    const newGrid = grid.map(row => [...row]);
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[i].length - 1; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    neighbors += grid[i + x][j + y];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1) {
                newGrid[i][j] = (neighbors === 2 || neighbors === 3) ? 1 : 0;
            } else {
                newGrid[i][j] = (neighbors === 3) ? 1 : 0;
            }
        }
    }
    return newGrid;
}

function main() {
    const gridSize = 50;
    const grid = Array.from({ length: gridSize }, () => 
        Array.from({ length: gridSize }, () => randomInt(0, 2))
    );
    while (true) {
        grid = updateGrid(grid);
    }
}

function randomInt(min, max) {
    return Math.floor(random() * (max - min + 1)) + min;
}

main();