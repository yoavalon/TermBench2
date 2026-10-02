function update_state(grid: number[][], x: number, y: number, size: number): number[][] {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        return grid;
    }
    let neighbors = 0;
    for (let i = -1; i < 2; i++) {
        for (let j = -1; j < 2; j++) {
            if (i === 0 && j === 0) {
                continue;
            }
            const nx = x + i;
            const ny = y + j;
            if (nx >= 0 && nx < size && ny >= 0 && ny < size) {
                neighbors += grid[nx][ny];
            }
        }
    }
    if (grid[x][y] === 1) {
        if (neighbors < 2 || neighbors > 3) {
            grid[x][y] = 0;
        }
    } else if (neighbors === 3) {
        grid[x][y] = 1;
    }
    return x < size - 1 ? update_state(grid, x + 1, y, size) : y < size - 1 ? update_state(grid, 0, y + 1, size) : grid;
}

function main() {
    const size = 10;
    const grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    grid[size // 2][size // 2] = 1;
    while (true) {
        grid = update_state(grid, 0, 0, size);
    }
}

main();