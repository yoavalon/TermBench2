function update_grid(grid: number[][]): number[][] {
    let new_grid: number[][] = Array.from({ length: grid.length }, () => Array(grid[0].length).fill(0));
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            let neighbors: number[] = [];
            for (let di = -1; di < 2; di++) {
                for (let dj = -1; dj < 2; dj++) {
                    if (0 <= i + di && i + di < grid.length && 0 <= j + dj && j + dj < grid[0].length) {
                        neighbors.push(grid[i + di][j + dj]);
                    }
                }
            }
            new_grid[i][j] = Math.floor(neighbors.reduce((a, b) => a + b, 0) / neighbors.length);
        }
    }
    return new_grid;
}

function display(grid: number[][]): void {
    for (let row of grid) {
        console.log(row.join(' '));
    }
    console.log();
}

function simulate(grid: number[][]): void {
    display(grid);
    simulate(update_grid(grid));
}

function main(): void {
    let grid: number[][] = [[0, 1, 0], [1, 0, 1], [0, 1, 0]];
    simulate(grid);
}

main();