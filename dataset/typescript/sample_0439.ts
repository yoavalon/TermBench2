const { randomInt } = require('crypto');

function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = grid.map(row => row.slice());

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let ni = Math.max(0, i - 1); ni < Math.min(rows, i + 2); ni++) {
                for (let nj = Math.max(0, j - 1); nj < Math.min(cols, j + 2); nj++) {
                    neighbors += grid[ni][nj];
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

function main() {
    const size = 50;
    const grid = Array.from({ length: size }, () => 
        Array.from({ length: size }, () => randomInt(2))
    );
    while (true) {
        grid.updateGrid(grid);
    }
}

main();