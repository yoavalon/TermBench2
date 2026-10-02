function update_state(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const new_grid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(rows, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(cols, j + 2); y++) {
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

function main() {
    let grid = [
        [0, 1, 0],
        [0, 1, 0],
        [0, 1, 0]
    ];
    while (true) {
        grid = update_state(grid);
        for (const row of grid) {
            console.log(row.map(cell => cell ? 'O' : '.').join(''));
        }
        console.log();
    }
}

main();