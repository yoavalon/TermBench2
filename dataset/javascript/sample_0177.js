function initGrid(size) {
    let grid = Array.from({ length: size }, () => Array(size).fill(0));
    grid[Math.floor(size / 2)][Math.floor(size / 2)] = 1;
    return grid;
}

function updateGrid(grid) {
    let newGrid = grid.map(row => [...row]);
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(grid[i].length, j + 2); y++) {
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

function main() {
    let size = 10;
    let grid = initGrid(size);
    let steps = 50;
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid);
    }
    console.log(grid);
}

main();