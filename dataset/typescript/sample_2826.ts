function initialize_grid(size: number): number[][] {
    let grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    grid[size // 2][size // 2] = 1;
    return grid;
}

function update_grid(grid: number[][]): number[][] {
    let new_grid: number[][] = grid.map(row => [...row]);
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            let neighbors = 0;
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[i].length && (x !== i || y !== j)) {
                        neighbors += grid[x][y];
                    }
                }
            }
            new_grid[i][j] = neighbors === 3 ? 1 : 0;
        }
    }
    return new_grid;
}

function main() {
    let size = 50;
    let grid = initialize_grid(size);
    while (true) {
        grid = update_grid(grid);
    }
}

main();