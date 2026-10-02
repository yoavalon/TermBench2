function updateGrid(grid: number[][]): number[][] {
    const size = grid.length;
    const newGrid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let x = 0; x < size; x++) {
        for (let y = 0; y < size; y++) {
            let neighbors = 0;
            for (let dx = -1; dx <= 1; dx++) {
                for (let dy = -1; dy <= 1; dy++) {
                    if (dx === 0 && dy === 0) continue;
                    neighbors += grid[(x + dx + size) % size][(y + dy + size) % size];
                }
            }
            newGrid[x][y] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
        }
    }
    return newGrid;
}

function simulate(grid: number[][]): void {
    const random = Math.random;
    if (grid.length === 0) {
        grid = Array.from({ length: 10 }, () => Array(10).fill(0).map(() => Math.floor(random() * 2)));
    }
    console.log(grid.map(row => row.join('')).join('\n'));
    simulate(updateGrid(grid));
}

simulate([]);