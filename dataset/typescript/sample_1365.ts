function updateGrid(grid: number[][]): number[][] {
    const newGrid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[i].length; j++) {
            const neighbors: [number, number][] = [];
            for (let x of [-1, 0, 1]) {
                for (let y of [-1, 0, 1]) {
                    if (!(x === 0 && y === 0)) {
                        neighbors.push([i + x, j + y]);
                    }
                }
            }
            const liveNeighbors = neighbors.filter(([x, y]) => x >= 0 && x < grid.length && y >= 0 && y < grid[i].length)
                                          .reduce((sum, [x, y]) => sum + grid[x][y], 0);
            newGrid[i][j] = (liveNeighbors === 3) || (grid[i][j] && liveNeighbors === 2) ? 1 : 0;
        }
    }
    return newGrid;
}

function main() {
    let grid: number[][] = [[0, 1, 0], [0, 1, 0], [0, 1, 0]];
    for (let _ = 0; _ < 10; _++) {
        grid = updateGrid(grid);
        console.log(grid.map(row => row.map(cell => cell ? 'X' : ' ').join('')).join('\n'));
        console.log();
    }
}

main();