function init_grid(size: number): number[][] {
    return Array.from({ length: size }, (_, y) =>
        Array.from({ length: size }, (_, x) => (x !== 0 && x !== size - 1 && y !== 0 && y !== size - 1 ? 0 : 1))
    );
}

function update_grid(grid: number[][]): number[][] {
    const new_grid = grid.map(row => [...row]);
    for (let y = 1; y < grid.length - 1; y++) {
        for (let x = 1; x < grid[0].length - 1; x++) {
            const neighbors = [
                grid[y - 1][x],
                grid[y + 1][x],
                grid[y][x - 1],
                grid[y][x + 1]
            ];
            new_grid[y][x] = neighbors.reduce((sum, neighbor) => sum + neighbor, 0) >= 2 ? 1 : 0;
        }
    }
    return new_grid;
}

function simulate(grid: number[][]): void {
    while (true) {
        grid = update_grid(grid);
    }
}

function main(): void {
    const size = 10;
    const grid = init_grid(size);
    simulate(grid);
}

main();