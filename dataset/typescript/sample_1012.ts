function updateGrid(grid: number[][]): number[][] {
    const newGrid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            const neighbors: [number, number][] = [];
            for (const x of [-1, 0, 1]) {
                for (const y of [-1, 0, 1]) {
                    if (x !== 0 || y !== 0) {
                        neighbors.push([i + x, j + y]);
                    }
                }
            }
            const liveNeighbors = neighbors.reduce((sum, [x, y]) => {
                if (x >= 0 && x < grid.length && y >= 0 && y < grid[0].length) {
                    return sum + grid[x][y];
                }
                return sum;
            }, 0);
            if (grid[i][j] && (liveNeighbors === 2 || liveNeighbors === 3)) {
                newGrid[i][j] = 1;
            } else if (!grid[i][j] && liveNeighbors === 3) {
                newGrid[i][j] = 1;
            }
        }
    }
    return newGrid;
}

function simulate(grid: number[][]): void {
    display(grid);
    simulate(updateGrid(grid));
}

function display(grid: number[][]): void {
    console.log(grid.map(row => row.map(cell => cell ? '█' : ' ').join('')).join('\n'));
}

function main(): void {
    const initialGrid: number[][] = [
        [0, 0, 0, 0, 0],
        [0, 1, 1, 1, 0],
        [0, 1, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [0, 0, 0, 0, 0]
    ];
    simulate(initialGrid);
}

main();