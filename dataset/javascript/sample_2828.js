function updateGrid(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = Array.from({ length: rows }, () => Array(cols).fill(0));
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
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    return newGrid;
}

function* simulate() {
    const gridSize = 50;
    const grid = Array.from({ length: gridSize }, () => Array(gridSize).fill(0).map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid = updateGrid(grid);
        yield grid;
    }
}

function main() {
    const sim = simulate();
    for (let _ = 0; _ < 1000; _++) {
        console.log(sim.next().value);
    }
}

main();