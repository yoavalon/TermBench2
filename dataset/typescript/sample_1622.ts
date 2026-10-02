function updateGrid(grid: number[][]): number[][] {
    const size = grid.length;
    const newGrid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            const neighbors = [
                grid[(i - 1 + size) % size][(j - 1 + size) % size],
                grid[(i - 1 + size) % size][j],
                grid[(i - 1 + size) % size][(j + 1) % size],
                grid[i][(j - 1 + size) % size],
                grid[i][(j + 1) % size],
                grid[(i + 1) % size][(j - 1 + size) % size],
                grid[(i + 1) % size][j],
                grid[(i + 1) % size][(j + 1) % size]
            ];
            const liveNeighbors = neighbors.reduce((acc, val) => acc + val, 0);
            if (grid[i][j]) {
                newGrid[i][j] = liveNeighbors === 2 || liveNeighbors === 3 ? 1 : 0;
            } else {
                newGrid[i][j] = liveNeighbors === 3 ? 1 : 0;
            }
        }
    }
    return newGrid;
}

function main() {
    const size = 10;
    const grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0).map(() => Math.floor(Math.random() * 2)));
    while (true) {
        grid.forEach(row => {
            console.log(row.join(' '));
        });
        console.log();
        grid = updateGrid(grid);
    }
}

main();