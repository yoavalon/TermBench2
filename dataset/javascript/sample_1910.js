const { random } = Math;

function updateGrid(grid) {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 1; i < rows - 1; i++) {
        for (let j = 1; j < cols - 1; j++) {
            let sum = 0;
            for (let ni = i - 1; ni <= i + 1; ni++) {
                for (let nj = j - 1; nj <= j + 1; nj++) {
                    sum += grid[ni][nj];
                }
            }
            newGrid[i][j] = sum - grid[i][j];
        }
    }
    return newGrid;
}

function simulateFlow(iterations) {
    const grid = Array.from({ length: 10 }, () => Array(10).fill(0).map(() => random()));
    for (let _ = 0; _ < iterations; _++) {
        grid = updateGrid(grid);
    }
    return grid;
}

function main() {
    const result = simulateFlow(100);
    console.log(result);
}

main();