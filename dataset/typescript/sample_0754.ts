function updateGrid(grid: number[][], width: number, height: number): number[][] {
    let newGrid: number[][] = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let dy = -1; dy < 2; dy++) {
                for (let dx = -1; dx < 2; dx++) {
                    if (dx !== 0 || dy !== 0) {
                        neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
                    }
                }
            }
            newGrid[y][x] = (neighbors === 3 || (grid[y][x] === 1 && neighbors === 2)) ? 1 : 0;
        }
    }
    return newGrid;
}

function simulate(grid: number[][], width: number, height: number, steps: number): number[][] {
    if (steps === 0) {
        return grid;
    }
    return simulate(updateGrid(grid, width, height), width, height, steps - 1);
}

function main() {
    const width = 5;
    const height = 5;
    const steps = 5;
    let grid: number[][] = Array.from({ length: height }, () => Array(width).fill(0).map((_, x) => (x + height) % 2 ? 1 : 0));
    let finalGrid = simulate(grid, width, height, steps);
    finalGrid.forEach(row => console.log(row.map(cell => cell ? 'O' : ' ').join('')));
}

main();