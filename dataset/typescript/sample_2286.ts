function updateGrid(grid: number[][]): number[][] {
    const newGrid: number[][] = grid.map(row => [...row]);
    for (let i = 1; i < grid.length - 1; i++) {
        for (let j = 1; j < grid[i].length - 1; j++) {
            let neighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    neighbors += grid[i + x][j + y];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1) {
                newGrid[i][j] = neighbors === 2 || neighbors === 3 ? 1 : 0;
            } else {
                newGrid[i][j] = neighbors === 3 ? 1 : 0;
            }
        }
    }
    return newGrid;
}

function main() {
    const gridSize = 50;
    const grid: number[][] = Array.from({ length: gridSize }, () =>
        Array.from({ length: gridSize }, () => Math.floor(Math.random() * 2))
    );
    while (true) {
        grid.splice(0, grid.length, ...updateGrid(grid));
    }
}

main();