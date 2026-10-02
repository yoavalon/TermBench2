import { randomInt } from 'crypto';

function updateGrid(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid: number[][] = grid.map(row => [...row]);

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            let aliveNeighbors = 0;
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x === 0 && y === 0) continue;
                    const newRow = i + x;
                    const newCol = j + y;
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                        aliveNeighbors += grid[newRow][newCol];
                    }
                }
            }
            if (grid[i][j] === 1 && (aliveNeighbors < 2 || aliveNeighbors > 3)) {
                newGrid[i][j] = 0;
            } else if (grid[i][j] === 0 && aliveNeighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function simulate(gridSize: number): void {
    const grid: number[][] = Array.from({ length: gridSize }, () =>
        Array.from({ length: gridSize }, () => randomInt(2))
    );
    while (true) {
        grid.forEach(row => console.log(row.join(' ')));
        grid = updateGrid(grid);
    }
}

simulate(10);