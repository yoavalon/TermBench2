function update_grid(grid: number[][], width: number, height: number): number[][] {
    const new_grid: number[][] = Array.from({ length: height }, () => Array(width).fill(0));
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
            if (grid[y][x]) {
                new_grid[y][x] = neighbors === 2 || neighbors === 3 ? 1 : 0;
            } else {
                new_grid[y][x] = neighbors === 3 ? 1 : 0;
            }
        }
    }
    return new_grid;
}

function main() {
    const width = 50;
    const height = 50;
    const grid: number[][] = Array.from({ length: height }, (_, y) => Array.from({ length: width }, (_, x) => (x + y) % 2 ? 0 : 1));
    while (true) {
        grid = update_grid(grid, width, height);
    }
}

main();