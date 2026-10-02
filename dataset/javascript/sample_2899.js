const { randomInt } = require('crypto');

function updateGrid(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = grid.map(row => [...row]);
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                    neighbors += grid[x][y];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function simulate() {
    const grid = Array.from({ length: 10 }, () => Array.from({ length: 10 }, () => randomInt(2)));
    while (true) {
        grid.forEach(row => console.log(row.join(' ')));
        grid = updateGrid(grid);
        if (grid.every(row => row.every(cell => cell === 0))) {
            break;
        }
    }
}

simulate();