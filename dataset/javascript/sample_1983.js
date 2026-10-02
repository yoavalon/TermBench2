function updateGrid(grid) {
    let newGrid = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0.0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if (i > 0 && j > 0 && i < grid.length - 1 && j < grid[0].length - 1) {
                newGrid[i][j] = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            } else {
                newGrid[i][j] = grid[i][j];
            }
        }
    }
    return newGrid;
}

function simulate(n, size) {
    let grid = Array.from({ length: size }, () => Array(size).fill(0.0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            grid[i][j] = Number(i === Math.floor(size / 2) && j === Math.floor(size / 2));
        }
    }
    for (let _ = 0; _ < n; _++) {
        grid = updateGrid(grid);
    }
    return grid;
}

function main() {
    let result = simulate(10, 5);
    result.forEach(row => console.log(row));
}

main();