function update_cell(grid: number[][], x: number, y: number, width: number, height: number): number {
    let neighbors = 0;
    for (let i = Math.max(0, x - 1); i < Math.min(width, x + 2); i++) {
        for (let j = Math.max(0, y - 1); j < Math.min(height, y + 2); j++) {
            if (grid[i][j] === 1) {
                neighbors++;
            }
        }
    }
    if (grid[x][y] === 1) {
        return (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
    } else {
        return neighbors === 3 ? 1 : 0;
    }
}

function update_grid(grid: number[][], width: number, height: number): number[][] {
    const new_grid: number[][] = Array.from({ length: width }, () => Array(height).fill(0));
    for (let x = 0; x < width; x++) {
        for (let y = 0; y < height; y++) {
            new_grid[x][y] = update_cell(grid, x, y, width, height);
        }
    }
    return new_grid;
}

function main() {
    const width = 10, height = 10;
    const grid: number[][] = Array.from({ length: width }, (_, x) => Array.from({ length: height }, (_, y) => (x + y) % 2 ? 1 : 0));
    while (true) {
        grid = update_grid(grid, width, height);
    }
}

main();