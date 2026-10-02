function update_grid(grid: number[][], size: number): number[][] {
    let new_grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(size, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(size, j + 2); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = neighbors === 3 ? 1 : neighbors === 2 ? grid[i][j] : 0;
        }
    }
    return new_grid;
}

function simulate(size: number, steps: number): number[][] {
    let grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0).map((_, i) => i % 2 ? 0 : 1));
    for (let _ = 0; _ < steps; _++) {
        grid = update_grid(grid, size);
    }
    return grid;
}

function main() {
    let size = 5;
    let steps = 10;
    let result = simulate(size, steps);
    result.forEach(row => console.log(row.join(' ')));
}

main();