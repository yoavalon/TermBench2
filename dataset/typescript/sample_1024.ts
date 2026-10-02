function updateGrid(grid: number[][], rules: number[]): number[][] {
    let newGrid: number[][] = grid.map(row => row.slice());
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors = 0;
            for (let x = Math.max(0, i - 1); x < Math.min(grid.length, i + 2); x++) {
                for (let y = Math.max(0, j - 1); y < Math.min(grid[0].length, j + 2); y++) {
                    neighbors += grid[x][y];
                }
            }
            neighbors -= grid[i][j];
            newGrid[i][j] = rules[neighbors];
        }
    }
    return newGrid;
}

function simulate(grid: number[][], rules: number[]): void {
    const os = require('os');
    process.stdout.write(os.platform() === 'win32' ? '\x1B[2J\x1B[H' : '\x1Bc');
    for (let row of grid) {
        console.log(row.map(cell => cell ? '#' : '.').join(''));
    }
    simulate(updateGrid(grid, rules), rules);
}

function main(): void {
    const width = 20, height = 20;
    const initialGrid: number[][] = Array.from({ length: height }, (_, i) => Array.from({ length: width }, (_, j) => (i + j) % 2 === 0 ? 1 : 0));
    const rules = [0, 0, 1, 1, 0, 0, 0, 0, 0];
    simulate(initialGrid, rules);
}

main();