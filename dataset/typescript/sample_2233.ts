function update_state(grid: number[][]): number[][] {
    const new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            const neighbors: number[] = [
                grid[(i - 1 + grid.length) % grid.length][(j - 1 + grid[0].length) % grid[0].length],
                grid[(i - 1 + grid.length) % grid.length][j],
                grid[(i - 1 + grid.length) % grid.length][(j + 1) % grid[0].length],
                grid[i][(j - 1 + grid[0].length) % grid[0].length],
                grid[i][(j + 1) % grid[0].length],
                grid[(i + 1) % grid.length][(j - 1 + grid[0].length) % grid[0].length],
                grid[(i + 1) % grid.length][j],
                grid[(i + 1) % grid.length][(j + 1) % grid[0].length]
            ];
            const live_neighbors = neighbors.reduce((acc, val) => acc + val, 0);
            if (grid[i][j] === 1) {
                if (live_neighbors < 2 || live_neighbors > 3) {
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else if (live_neighbors === 3) {
                new_grid[i][j] = 1;
            } else {
                new_grid[i][j] = 0;
            }
        }
    }
    return new_grid;
}

function main() {
    let grid: number[][] = [
        [0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
    ];
    while (true) {
        grid = update_state(grid);
        for (const row of grid) {
            console.log(row.join(' '));
        }
        console.log();
    }
}

main();