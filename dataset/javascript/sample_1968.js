function updateGrid(grid) {
    let newGrid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0.0));
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[0].length - 1; j++) {
            let avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            newGrid[i][j] = (grid[i][j] + avg) / 2.0;
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
    let gridSize = 10;
    let steps = 5;
    let grid = Array.from({ length: gridSize }, () => Array(gridSize).fill(0.0));
    grid[gridSize // 2][gridSize // 2] = 1.0;
    let result = simulate(grid, steps);
    result.forEach(row => {
        console.log(row.map(x => x.toFixed(2)).join(' '));
    });
}

main();