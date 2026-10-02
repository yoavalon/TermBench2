function updateGrid(grid, width, height) {
    let newGrid = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let [dx, dy] of [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]) {
                neighbors += grid[(y + dy) % height][(x + dx) % width];
            }
            newGrid[y][x] = (neighbors === 3 || (grid[y][x] && neighbors === 2)) ? 1 : 0;
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
    let width = 10;
    let height = 10;
    let initialGrid = Array.from({ length: height }, () => Array(width).fill(0).map((_, x) => x % 2 ? 0 : 1));
    let steps = 5;
    let finalGrid = simulate(initialGrid, width, height, steps);
    for (let row of finalGrid) {
        console.log(row.join(' '));
    }
}

main();