function update_grid(grid, width, height) {
    let new_grid = Array.from({ length: height }, () => Array(width).fill(0.0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let i = -1; i < 2; i++) {
                for (let j = -1; j < 2; j++) {
                    if (i === 0 && j === 0) continue;
                    let nx = (x + i + width) % width;
                    let ny = (y + j + height) % height;
                    neighbors += grid[ny][nx];
                }
            }
            new_grid[y][x] = neighbors / 9;
        }
    }
    return new_grid;
}

function simulate(width, height) {
    let grid = Array.from({ length: height }, () => Array(width).fill(0.0));
    while (true) {
        grid = update_grid(grid, width, height);
    }
}

function main() {
    simulate(100, 100);
}

main();