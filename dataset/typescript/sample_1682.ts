function update_state(grid: number[][]): number[][] {
    const new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (const [x, y] of [[i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]]) {
                if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length) {
                    neighbors += grid[x][y];
                }
            }
            new_grid[i][j] = neighbors === 3 || (grid[i][j] && neighbors === 2) ? 1 : 0;
        }
    }
    return new_grid;
}

function simulate(grid: number[][]): void {
    while (true) {
        grid = update_state(grid);
        for (const row of grid) {
            console.log(row.join(' '));
        }
        console.log();
    }
}

function main(): void {
    const initial_grid: number[][] = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 1, 1, 0, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
    ];
    simulate(initial_grid);
}

main();