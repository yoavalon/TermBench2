function update_grid(grid: number[][], width: number, height: number): number[][] {
    let new_grid: number[][] = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let dy = -1; dy <= 1; dy++) {
                for (let dx = -1; dx <= 1; dx++) {
                    if (dx !== 0 || dy !== 0) {
                        neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                    }
                }
            }
            new_grid[y][x] = neighbors === 3 ? 1 : grid[y][x];
        }
    }
    return new_grid;
}

function simulate(grid: number[][], width: number, height: number, steps: number): number[][] {
    if (steps === 0) {
        return grid;
    }
    return simulate(update_grid(grid, width, height), width, height, steps - 1);
}

function main() {
    const width = 10;
    const height = 10;
    const steps = 5;
    const initial_grid: number[][] = Array.from({ length: height }, (_, y) => Array.from({ length: width }, (_, x) => x !== y ? 0 : 1));
    const final_grid = simulate(initial_grid, width, height, steps);
    final_grid.forEach(row => console.log(row.join(' ')));
}

main();