function update_grid(grid: number[][], width: number, height: number): number[][] {
    let new_grid: number[][] = Array.from({ length: height }, () => Array(width).fill(0.0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors: number = 0.0;
            for (let dy = -1; dy < 2; dy++) {
                for (let dx = -1; dx < 2; dx++) {
                    if (dx === 0 && dy === 0) {
                        continue;
                    }
                    let nx: number = x + dx;
                    let ny: number = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            new_grid[y][x] = grid[y][x] + 0.1 * (neighbors - 2.0 * grid[y][x]);
        }
    }
    return new_grid;
}

function main() {
    let width: number = 10;
    let height: number = 10;
    let grid: number[][] = Array.from({ length: height }, (y) => Array.from({ length: width }, (x) => x === y ? 0.0 : 1.0));
    for (let i = 0; i < 100; i++) {
        grid = update_grid(grid, width, height);
    }
    console.log(grid);
}

main();