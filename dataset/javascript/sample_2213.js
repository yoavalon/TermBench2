function initializeGrid(size) {
    let grid = [];
    for (let i = 0; i < size; i++) {
        let row = [];
        for (let j = 0; j < size; j++) {
            row.push(Math.random());
        }
        grid.push(row);
    }
    return grid;
}

function evolve(grid, steps) {
    for (let _ = 0; _ < steps; _++) {
        let newGrid = [];
        for (let i = 0; i < grid.length; i++) {
            let newRow = [];
            for (let j = 0; j < grid[i].length; j++) {
                let sum = grid[(i + 1) % grid.length][j] + grid[(i - 1 + grid.length) % grid.length][j] +
                          grid[i][(j + 1) % grid[i].length] + grid[i][(j - 1 + grid[i].length) % grid[i].length];
                newRow.push(Math.min(Math.max(sum, 0), 1));
            }
            newGrid.push(newRow);
        }
        grid = newGrid;
    }
    return grid;
}

function main() {
    let size = 100;
    let grid = initializeGrid(size);
    while (true) {
        grid = evolve(grid, 10);
        console.log(grid);
    }
}

main();