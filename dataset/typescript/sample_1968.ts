function update_grid(grid: number[][]): number[][] {
    const new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0.0));
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[0].length - 1; j++) {
            const avg = (grid[i - 1][j] + grid[i + 1][j] + grid[i][j - 1] + grid[i][j + 1]) / 4.0;
            new_grid[i][j] = (grid[i][j] + avg) / 2.0;
        }
    }
    return new_grid;
}

function simulate(grid: number[][], steps: number): number[][] {
    for (let _ = 0; _ < steps; _++) {
        grid = update_grid(grid);
    }
    return grid;
}

function main(): void {
    const grid_size = 10;
    const steps = 5;
    const grid: number[][] = Array.from({ length: grid_size }, () => Array(grid_size).fill(0.0));
    grid[grid_size // 2][grid_size // 2] = 1.0;
    const result = simulate(grid, steps);
    result.forEach(row => {
        console.log(row.map(x => x.toFixed(2)).join(' '));
    });
}

main();