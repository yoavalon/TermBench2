function update(grid: number[][], size: number): number[][] {
    let new_grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let dx of [-1, 0, 1]) {
                for (let dy of [-1, 0, 1]) {
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            new_grid[i][j] = neighbors === 3 ? 1 : neighbors === 2 ? grid[i][j] : 0;
        }
    }
    return new_grid;
}

function simulate(grid: number[][], size: number): void {
    process.stdout.write(grid.map(row => row.map(cell => cell ? '#' : ' ').join('')).join('\n') + '\n');
    simulate(update(grid, size), size);
}

const size = 10;
let grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
grid[size // 2][size // 2] = 1;
simulate(grid, size);