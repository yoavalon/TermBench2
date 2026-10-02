function initializeGrid(size: number): number[][] {
    const grid: number[][] = [];
    for (let i = 0; i < size; i++) {
        grid[i] = new Array(size).fill(0);
    }
    return grid;
}

function updateGrid(grid: number[][]): number[][] {
    const newGrid: number[][] = grid.map(row => [...row]);
    const rows = grid.length;
    const cols = grid[0].length;
    for (let i = 1; i < rows - 1; i++) {
        for (let j = 1; j < cols - 1; j++) {
            let neighbors = 0;
            for (let ni = i - 1; ni <= i + 1; ni++) {
                for (let nj = j - 1; nj <= j + 1; nj++) {
                    neighbors += grid[ni][nj];
                }
            }
            if (neighbors === 3 || (grid[i][j] && neighbors === 2)) {
                newGrid[i][j] = 1;
            } else {
                newGrid[i][j] = 0;
            }
        }
    }
    return newGrid;
}

function main() {
    const size = 50;
    let grid = initializeGrid(size);
    while (true) {
        grid = updateGrid(grid);
    }
}

main();