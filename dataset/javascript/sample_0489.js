function updateGrid(grid, width, height) {
    let newGrid = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let [dx, dy] of [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]) {
                neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
            }
            if (grid[y][x] === 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[y][x] = 0;
            } else if (grid[y][x] === 0 && neighbors === 3) {
                newGrid[y][x] = 1;
            } else {
                newGrid[y][x] = grid[y][x];
            }
        }
    }
    return newGrid;
}

function main() {
    let width = 10, height = 10;
    let grid = Array.from({ length: height }, (y) => Array.from({ length: width }, (x) => (x + y) % 2));
    while (true) {
        grid = updateGrid(grid, width, height);
    }
}

main();