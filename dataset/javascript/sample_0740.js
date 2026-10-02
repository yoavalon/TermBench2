function updateState(grid, width, height) {
    let newGrid = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let dy = -1; dy <= 1; dy++) {
                for (let dx = -1; dx <= 1; dx++) {
                    if (dy === 0 && dx === 0) continue;
                    let nx = x + dx, ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            if (grid[y][x] === 1) {
                newGrid[y][x] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            } else {
                newGrid[y][x] = (neighbors === 3) ? 1 : 0;
            }
        }
    }
    return newGrid;
}

function simulate(grid, width, height, steps) {
    if (steps === 0) {
        return grid;
    } else {
        return simulate(updateState(grid, width, height), width, height, steps - 1);
    }
}

function main() {
    let width = 50, height = 50, steps = 100;
    let grid = Array.from({ length: height }, (row, y) => Array.from({ length: width }, (cell, x) => (x + y) % 2 ? 1 : 0));
    let finalGrid = simulate(grid, width, height, steps);
    finalGrid.forEach(row => console.log(row.map(cell => cell ? 'O' : ' ').join('')));
}

main();