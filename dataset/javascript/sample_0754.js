function updateGrid(grid, width, height) {
    let newGrid = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let dy = -1; dy < 2; dy++) {
                for (let dx = -1; dx < 2; dx++) {
                    if (dx !== 0 || dy !== 0) {
                        neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                    }
                }
            }
            newGrid[y][x] = neighbors === 3 || (grid[y][x] && neighbors === 2) ? 1 : 0;
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
    let width = 5, height = 5, steps = 5;
    let grid = Array.from({ length: height }, (_, y) => Array.from({ length: width }, (_, x) => (x + y) % 2 ? 1 : 0));
    let finalGrid = simulate(grid, width, height, steps);
    finalGrid.forEach(row => {
        console.log(row.map(cell => cell ? 'O' : ' ').join(''));
    });
}

main();