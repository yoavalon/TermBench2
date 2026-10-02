function updateGrid(grid, width, height) {
    let newGrid = Array.from({ length: height }, () => Array(width).fill(0.0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = [];
            for (let dy of [-1, 0, 1]) {
                for (let dx of [-1, 0, 1]) {
                    if (dy !== 0 || dx !== 0) {
                        neighbors.push(grid[(y + dy + height) % height][(x + dx + width) % width]);
                    }
                }
            }
            newGrid[y][x] = neighbors.reduce((acc, val) => acc + val, 0) / neighbors.length;
        }
    }
    return newGrid;
}

function simulate(width, height, steps) {
    let grid = Array.from({ length: height }, (y) => Array.from({ length: width }, (x) => x + y));
    for (let i = 0; i < steps; i++) {
        grid = updateGrid(grid, width, height);
    }
    return grid;
}

function main() {
    let width = 10;
    let height = 10;
    let steps = 5;
    let finalGrid = simulate(width, height, steps);
    finalGrid.forEach(row => console.log(row));
}

main();