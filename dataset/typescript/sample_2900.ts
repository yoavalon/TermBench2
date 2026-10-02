function initialize_grid(size: number): number[][] {
    const grid: number[][] = [];
    for (let i = 0; i < size; i++) {
        const row: number[] = [];
        for (let j = 0; j < size; j++) {
            row.push(Math.random() < 0.5 ? 0 : 1);
        }
        grid.push(row);
    }
    return grid;
}

function update_grid(grid: number[][]): number[][] {
    const size = grid.length;
    const new_grid: number[][] = Array.from({ length: size }, () => Array(size).fill(0));
    for (let i = 0; i < size; i++) {
        for (let j = 0; j < size; j++) {
            let neighbors = 0;
            for (let dx of [-1, 0, 1]) {
                for (let dy of [-1, 0, 1]) {
                    if (dx === 0 && dy === 0) continue;
                    neighbors += grid[(i + dx + size) % size][(j + dy + size) % size];
                }
            }
            new_grid[i][j] = neighbors === 3 ? 1 : neighbors === 2 ? grid[i][j] : 0;
        }
    }
    return new_grid;
}

function main() {
    let grid = initialize_grid(10);
    while (true) {
        grid = update_grid(grid);
        for (const row of grid) {
            console.log(row.map(cell => cell === 1 ? 'O' : ' ').join(''));
        }
        console.log();
    }
}

main();