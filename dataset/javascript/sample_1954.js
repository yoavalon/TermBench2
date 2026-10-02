function updateGrid(grid, width, height) {
    let newGrid = Array.from({ length: height }, () => Array(width).fill(0.0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0.0;
            for (let dy = -1; dy < 2; dy++) {
                for (let dx = -1; dx < 2; dx++) {
                    if (dx === 0 && dy === 0) continue;
                    let nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            newGrid[y][x] = grid[y][x] + 0.1 * (neighbors - 2.0 * grid[y][x]);
        }
    }
    return newGrid;
}

function main() {
    let width = 10, height = 10;
    let grid = Array.from({ length: height }, (_, y) => Array(width).fill(y === 0 ? 0.0 : 1.0));
    for (let i = 0; i < 100; i++) {
        grid = updateGrid(grid, width, height);
    }
    console.log(grid);
}

main();