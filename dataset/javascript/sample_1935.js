function updateGrid(grid) {
    const newGrid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    const rows = grid.length;
    const cols = grid[0].length;
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let ni = Math.max(0, i - 1); ni < Math.min(rows, i + 2); ni++) {
                for (let nj = Math.max(0, j - 1); nj < Math.min(cols, j + 2); nj++) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1) {
                newGrid[i][j] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            } else {
                newGrid[i][j] = (neighbors === 3) ? 1 : 0;
            }
        }
    }
    return newGrid;
}

function main() {
    const gridSize = 10;
    const grid = Array.from({ length: gridSize }, () => Array(gridSize).fill(0));
    grid[gridSize // 2][gridSize // 2] = 1;
    const steps = 50;
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid);
    }
    console.log(grid);
}

main();