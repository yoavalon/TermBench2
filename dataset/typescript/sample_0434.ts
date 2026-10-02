function updateCell(state: number, neighbors: number[]): number {
    const activeNeighbors = neighbors.reduce((sum, neighbor) => sum + neighbor, 0);
    if (state === 1) {
        return activeNeighbors === 2 || activeNeighbors === 3 ? 1 : 0;
    } else {
        return activeNeighbors === 3 ? 1 : 0;
    }
}

function simulate(grid: number[][]): number[][] {
    const rows = grid.length;
    const cols = grid[0].length;
    const newGrid: number[][] = Array.from({ length: rows }, () => Array(cols).fill(0));
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            const neighbors: number[] = [];
            for (let x = -1; x <= 1; x++) {
                for (let y = -1; y <= 1; y++) {
                    if (x === 0 && y === 0) continue;
                    const ni = i + x;
                    const nj = j + y;
                    if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                        neighbors.push(grid[ni][nj]);
                    }
                }
            }
            newGrid[i][j] = updateCell(grid[i][j], neighbors);
        }
    }
    return newGrid;
}

function main() {
    const grid: number[][] = [
        [0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0],
        [0, 0, 0, 0, 0]
    ];
    while (true) {
        grid = simulate(grid);
    }
}

main();