function updateGrid(grid, width, height) {
    let newGrid = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let ny = Math.max(0, y - 1); ny < Math.min(height, y + 2); ny++) {
                for (let nx = Math.max(0, x - 1); nx < Math.min(width, x + 2); nx++) {
                    neighbors += grid[ny][nx];
                }
            }
            neighbors -= grid[y][x];
            newGrid[y][x] = (neighbors === 3 || (neighbors === 2 && grid[y][x] === 1)) ? 1 : 0;
        }
    }
    return newGrid;
}

function simulate(grid, width, height, steps) {
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid, width, height);
    }
    return grid;
}

function main() {
    const width = 10;
    const height = 10;
    const steps = 5;
    let initialGrid = Array.from({ length: height }, () => Array(width).fill(0));
    initialGrid[5][5] = 1;
    let result = simulate(initialGrid, width, height, steps);
    result.forEach(row => console.log(row.map(cell => cell ? 'O' : ' ').join('')));
}

main();