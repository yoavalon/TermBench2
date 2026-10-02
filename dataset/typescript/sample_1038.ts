function updateGrid(grid: number[][], width: number, height: number): number[][] {
    let newGrid: number[][] = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let i = -1; i < 2; i++) {
                for (let j = -1; j < 2; j++) {
                    let nx = (x + i + width) % width;
                    let ny = (y + j + height) % height;
                    neighbors += grid[ny][nx];
                }
            }
            newGrid[y][x] = (neighbors > 2 && neighbors < 4) ? 1 : 0;
        }
    }
    return newGrid;
}

function simulate(grid: number[][], width: number, height: number): void {
    printGrid(grid, width, height);
    simulate(updateGrid(grid, width, height), width, height);
}

function printGrid(grid: number[][], width: number, height: number): void {
    for (let y = 0; y < height; y++) {
        console.log(grid[y].map(x => x ? '#' : ' ').join(''));
    }
}

function main(): void {
    let width = 50;
    let height = 50;
    let grid: number[][] = Array.from({ length: height }, () => Array(width).fill(0));
    grid[25][25] = 1;
    simulate(grid, width, height);
}

main();