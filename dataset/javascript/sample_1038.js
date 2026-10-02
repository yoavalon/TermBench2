function update_grid(grid, width, height) {
    let new_grid = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let i = -1; i < 2; i++) {
                for (let j = -1; j < 2; j++) {
                    let nx = (x + i + width) % width;
                    let ny = (y + j + height) % height;
                    neighbors += grid[ny][nx];
                }
            }
            new_grid[y][x] = (neighbors > 2 && neighbors < 4) ? 1 : 0;
        }
    }
    return new_grid;
}

function simulate(grid, width, height) {
    print_grid(grid, width, height);
    simulate(update_grid(grid, width, height), width, height);
}

function print_grid(grid, width, height) {
    for (let y = 0; y < height; y++) {
        console.log(grid[y].map(cell => cell ? '#' : ' ').join(''));
    }
}

function main() {
    let width = 50;
    let height = 50;
    let grid = Array.from({ length: height }, () => Array(width).fill(0));
    grid[25][25] = 1;
    simulate(grid, width, height);
}

main();