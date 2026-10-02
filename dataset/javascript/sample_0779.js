function updateGrid(grid, width, height) {
    let newGrid = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let dx of [-1, 0, 1]) {
                for (let dy of [-1, 0, 1]) {
                    if (dx !== 0 || dy !== 0) {
                        neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                    }
                }
            }
            newGrid[y][x] = neighbors === 3 ? 1 : grid[y][x];
        }
    }
    return newGrid;
}

function simulate(grid, width, height, steps) {
    if (steps === 0) {
        return grid;
    }
    return simulate(updateGrid(grid, width, height), width, height, steps - 1);
}

function main() {
    let width = 10, height = 10, steps = 5;
    let initialGrid = Array.from({ length: height }, (y) => Array(width).fill(0).map((_, x) => x === y ? 1 : 0));
    let finalGrid = simulate(initialGrid, width, height, steps);
    finalGrid.forEach((row) => console.log(row.join(' ')));
}

main();