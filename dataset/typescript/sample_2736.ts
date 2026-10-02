function main() {
    function update(grid: number[][]): number[][] {
        const rows = grid.length;
        const cols = grid[0].length;
        const newGrid = Array.from({ length: rows }, () => Array(cols).fill(0));

        for (let i = 0; i < rows; i++) {
            for (let j = 0; j < cols; j++) {
                const top = grid[(i - 1 + rows) % rows][j];
                const bottom = grid[(i + 1) % rows][j];
                const left = grid[i][(j - 1 + cols) % cols];
                const right = grid[i][(j + 1) % cols];
                newGrid[i][j] = (grid[i][j] + top + bottom + left + right) % 2;
            }
        }
        return newGrid;
    }

    const rows = 100;
    const cols = 100;
    let grid = Array.from({ length: rows }, () => Array(cols).fill(0));
    grid[50][50] = 1;

    while (true) {
        grid = update(grid);
    }
}

main();