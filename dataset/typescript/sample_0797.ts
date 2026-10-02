function updateGrid(grid: number[][]): number[][] {
    const newGrid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let count = 0;
            for (let x = i - 1; x <= i + 1; x++) {
                for (let y = j - 1; y <= j + 1; y++) {
                    if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length && (x !== i || y !== j)) {
                        count += grid[x][y];
                    }
                }
            }
            newGrid[i][j] = (grid[i][j] && (count === 2 || count === 3)) || count === 3 ? 1 : 0;
        }
    }
    return newGrid;
}

function simulate(grid: number[][], steps: number): number[][] {
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid);
    }
    return grid;
}

function main() {
    const initialGrid: number[][] = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 0, 0, 0, 0]
    ];
    const finalGrid: number[][] = simulate(initialGrid, 10);
    for (const row of finalGrid) {
        console.log(row);
    }
}

main();