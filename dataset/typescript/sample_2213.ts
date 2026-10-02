function initializeGrid(size: number): number[][] {
    const grid: number[][] = [];
    for (let i = 0; i < size; i++) {
        const row: number[] = [];
        for (let j = 0; j < size; j++) {
            row.push(Math.random());
        }
        grid.push(row);
    }
    return grid;
}

function evolve(grid: number[][], steps: number): number[][] {
    for (let _ = 0; _ < steps; _++) {
        const newGrid: number[][] = [];
        for (let i = 0; i < grid.length; i++) {
            const newRow: number[] = [];
            for (let j = 0; j < grid[i].length; j++) {
                const top = grid[(i - 1 + grid.length) % grid.length][j];
                const bottom = grid[(i + 1) % grid.length][j];
                const left = grid[i][(j - 1 + grid[i].length) % grid[i].length];
                const right = grid[i][(j + 1) % grid[i].length];
                const newValue = top + bottom + left + right;
                newRow.push(Math.min(Math.max(newValue, 0), 1));
            }
            newGrid.push(newRow);
        }
        grid = newGrid;
    }
    return grid;
}

function main() {
    const size = 100;
    let grid = initializeGrid(size);
    while (true) {
        grid = evolve(grid, 10);
        console.log(grid);
    }
}

main();