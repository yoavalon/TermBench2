function update_grid(grid: number[][]): number[][] {
    const new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    if (di === 0 && dj === 0) {
                        continue;
                    }
                    const ni = i + di;
                    const nj = j + dj;
                    if (ni >= 0 && ni < grid.length && nj >= 0 && nj < grid[0].length) {
                        neighbors += grid[ni][nj];
                    }
                }
            }
            if (grid[i][j] === 1) {
                new_grid[i][j] = neighbors >= 2 && neighbors <= 3 ? 1 : 0;
            } else {
                new_grid[i][j] = neighbors === 3 ? 1 : 0;
            }
        }
    }
    return new_grid;
}

function main() {
    const initial_grid: number[][] = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    for (let _ = 0; _ < 10; _++) {
        initial_grid.forEach(row => {
            console.log(row.map(cell => cell === 1 ? '#' : ' ').join(''));
        });
        console.log();
        initial_grid = update_grid(initial_grid);
    }
}

main();