const { randomInt } = require('crypto');

function updateGrid(grid) {
    const newGrid = grid.map(row => [...row]);
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[i].length - 1; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (!grid[i][j] && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function simulate(grid, steps) {
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid);
    }
    return grid;
}

function main() {
    const size = 50;
    const grid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 20; i < 25; i++) {
        for (let j = 20; j < 25; j++) {
            grid[i][j] = randomInt(2);
        }
    }
    const finalGrid = simulate(grid, 100);
    console.log(finalGrid);
}

main();