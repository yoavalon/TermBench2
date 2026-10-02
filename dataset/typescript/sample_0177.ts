function initGrid(size: number): number[][] {
    const grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    grid[Math.floor(size / 2)][Math.floor(size / 2)] = 1;
    return grid;
}

function updateGrid(grid: number[][]): number[][] {
    const newGrid: number[][] = grid.map(row => [...row]);
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (let ni = Math.max(0, i - 1); ni < Math.min(grid.length, i + 2); ni++) {
                for (let nj = Math.max(0, j - 1); nj < Math.min(grid[0].length, j + 2); nj++) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function main() {
    const size = 10;
    let grid = initGrid(size);
    const steps = 50;
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid);
    }
    console.log(grid);
}

main();