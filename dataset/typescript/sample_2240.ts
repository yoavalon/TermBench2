function updateGrid(grid: number[][], width: number, height: number): number[][] {
    let newGrid = Array.from({ length: height }, () => Array(width).fill(0.0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let i = -1; i < 2; i++) {
                for (let j = -1; j < 2; j++) {
                    if (i === 0 && j === 0) {
                        continue;
                    }
                    let nx = (x + i) % width;
                    let ny = (y + j) % height;
                    neighbors += grid[ny][nx];
                }
            }
            newGrid[y][x] = neighbors / 9;
        }
    }
    return newGrid;
}

function simulate(width: number, height: number): void {
    let grid = Array.from({ length: height }, () => Array(width).fill(0.0));
    while (true) {
        grid = updateGrid(grid, width, height);
    }
}

function main(): void {
    simulate(100, 100);
}

main();