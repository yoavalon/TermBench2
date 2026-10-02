function updateGrid(grid, size) {
    let newGrid = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            newGrid[i][j] = neighbors === 3 ? 1 : neighbors === 2 ? grid[i][j] : 0;
        }
    }
    return newGrid;
}

function simulate(size, steps) {
    let grid = Array.from({ length: size }, (_, i) => Array(size).fill(i % 2 ? 0 : 1));
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid, size);
    }
    return grid;
}

function main() {
    let size = 5;
    let steps = 10;
    let result = simulate(size, steps);
    result.forEach(row => console.log(row.join(' ')));
}

main();