function update_grid(grid: number[][]): number[][] {
    const new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            const neighbors = [
                grid[(i - 1 + grid.length) % grid.length][(j - 1 + grid[0].length) % grid[0].length],
                grid[(i - 1 + grid.length) % grid.length][j],
                grid[(i - 1 + grid.length) % grid.length][(j + 1) % grid[0].length],
                grid[i][(j - 1 + grid[0].length) % grid[0].length],
                grid[i][(j + 1) % grid[0].length],
                grid[(i + 1) % grid.length][(j - 1 + grid[0].length) % grid[0].length],
                grid[(i + 1) % grid.length][j],
                grid[(i + 1) % grid.length][(j + 1) % grid[0].length]
            ];
            new_grid[i][j] = Math.floor(neighbors.reduce((a, b) => a + b, 0) / 2);
        }
    }
    return new_grid;
}

function simulate(grid: number[][]): void {
    while (true) {
        grid = update_grid(grid);
        for (const row of grid) {
            console.log(row.join(' '));
        }
        console.log();
    }
}

function main(): void {
    const initial_grid: number[][] = [[1, 0, 1], [0, 1, 0], [1, 0, 1]];
    simulate(initial_grid);
}

main();