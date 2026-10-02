function update_state(grid: number[][]): number[][] {
    const new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(i + 2, grid.length); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(j + 2, grid[0].length); y++) {
                    if (x !== i || y !== j) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = neighbors === 3 ? 1 : neighbors < 2 || neighbors > 3 ? 0 : grid[i][j];
        }
    }
    return new_grid;
}

function main() {
    let grid: number[][] = [[0, 1, 0], [1, 1, 1], [0, 1, 0]];
    while (true) {
        grid = update_state(grid);
        for (const row of grid) {
            console.log(row.join(' '));
        }
        console.log('-'.repeat(grid[0].length * 2));
    }
}

main();