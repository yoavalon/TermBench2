function updateGrid(grid: number[][], width: number, height: number): number[][] {
    let newGrid: number[][] = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let [dx, dy] of [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]) {
                neighbors += grid[(y + dy + height) % height][(x + dx + width) % width];
            }
            newGrid[y][x] = neighbors === 3 || (grid[y][x] && neighbors === 2) ? 1 : 0;
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
    const width = 10;
    const height = 10;
    const initialGrid: number[][] = Array.from({ length: height }, () => Array.from({ length: width }, (x) => x % 2 ? 0 : 1));
    const steps = 5;
    const finalGrid = simulate(initialGrid, width, height, steps);
    for (let row of finalGrid) {
        console.log(row.join(' '));
    }
}

main();