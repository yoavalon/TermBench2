function updateGrid(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            newGrid[i][j] = neighbors === 3 || (grid[i][j] && neighbors === 2) ? 1 : 0;
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
    const initialGrid = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    const steps = 5;
    const finalGrid = simulate(initialGrid, steps);
    finalGrid.forEach(row => console.log(row.join(' ')));
}

main();