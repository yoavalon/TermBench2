function update_state(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const new_grid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0.0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            const neighbors: [number, number][] = [
                [i - 1, j], [i + 1, j], [i, j - 1], [i, j + 1]
            ];
            const value = neighbors.reduce((sum, [x, y]) => {
                if (x >= 0 && x < rows && y >= 0 && y < cols) {
                    return sum + grid[x][y];
                }
                return sum;
            }, 0);
            new_grid[i][j] = value / 4.0;
        }
    }
    return new_grid;
}

function simulate(grid: number[][]): void {
    while (true) {
        grid = update_state(grid);
    }
}

function main(): void {
    const grid_size = 10;
    const initial_grid: number[][] = Array.from({ length: grid_size }, (_, i) =>
        Array.from({ length: grid_size }, (_, j) => float(i * j))
    );
    simulate(initial_grid);
}

main();