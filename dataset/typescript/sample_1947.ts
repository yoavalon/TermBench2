function updateGrid(grid: number[][], width: number, height: number): number[][] {
    let newGrid: number[][] = Array.from({ length: height }, () => Array(width).fill(0.0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors: number[] = [];
            for (let dy of [-1, 0, 1]) {
                for (let dx of [-1, 0, 1]) {
                    if (dy !== 0 || dx !== 0) {
                        neighbors.push(grid[(y + dy + height) % height][(x + dx + width) % width]);
                    }
                }
            }
            newGrid[y][x] = neighbors.reduce((acc, val) => acc + val, 0) / neighbors.length;
        }
    }
    return newGrid;
}

function simulate(width: number, height: number, steps: number): number[][] {
    let grid: number[][] = Array.from({ length: height }, (y) => Array.from({ length: width }, (x) => x + y));
    for (let _ = 0; _ < steps; _++) {
        grid = updateGrid(grid, width, height);
    }
    return grid;
}

function main() {
    let width = 10, height = 10, steps = 5;
    let finalGrid = simulate(width, height, steps);
    for (let row of finalGrid) {
        console.log(row);
    }
}

main();