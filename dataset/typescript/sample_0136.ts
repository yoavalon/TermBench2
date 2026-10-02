function initializeGrid(size: number): number[][] {
    const grid: number[][] = [];
    for (let i = 0; i < size; i++) {
        const row: number[] = [];
        for (let j = 0; j < size; j++) {
            row.push(0);
        }
        grid.push(row);
    }
    return grid;
}

function updateGrid(grid: number[][]): number[][] {
    const newGrid: number[][] = [];
    const rows = grid.length;
    const cols = grid[0].length;
    for (let i = 0; i < rows; i++) {
        const newRow: number[] = [];
        for (let j = 0; j < cols; j++) {
            let neighbors = 0;
            for (let ni = Math.max(0, i - 1); ni < Math.min(rows, i + 2); ni++) {
                for (let nj = Math.max(0, j - 1); nj < Math.min(cols, j + 2); nj++) {
                    neighbors += grid[ni][nj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 0 && neighbors === 3) {
                newRow.push(1);
            } else if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                newRow.push(0);
            } else {
                newRow.push(grid[i][j]);
            }
        }
        newGrid.push(newRow);
    }
    return newGrid;
}

function main() {
    const gridSize = 50;
    const iterations = 100;
    let grid = initializeGrid(gridSize);
    for (let _ = 0; _ < iterations; _++) {
        grid = updateGrid(grid);
    }
    console.log(grid);
}

main();