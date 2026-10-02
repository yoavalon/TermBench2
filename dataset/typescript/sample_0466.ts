function update_cell(grid: number[][], i: number, j: number, size: number): boolean {
    let neighbors = 0;
    for (let x = i - 1; x < i + 2; x++) {
        for (let y = j - 1; y < j + 2; y++) {
            if (x >= 0 && x < size && y >= 0 && y < size && (x !== i || y !== j)) {
                neighbors += grid[x][y];
            }
        }
    }
    return neighbors === 3 || (grid[i][j] === 1 && neighbors === 2);
}

function step(grid: number[][]): number[][] {
    const size = grid.length;
    const new_grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            new_grid[i][j] = update_cell(grid, i, j, size) ? 1 : 0;
        }
    }
    return new_grid;
}

function main() {
    const size = 10;
    let grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    grid[1][1] = 1;
    grid[2][2] = 1;
    grid[2][1] = 1;
    while (true) {
        grid = step(grid);
    }
}

main();