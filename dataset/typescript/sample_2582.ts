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
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    if (di === 0 && dj === 0) continue;
                    neighbors += grid[(i + di + size) % size][(j + dj + size) % size];
                }
            }
            new_grid[i][j] = neighbors === 3 || (grid[i][j] === 1 && neighbors === 2) ? 1 : 0;
        }
    }
    return new_grid;
}

function simulate(steps: number, size: number): number[][] {
    let grid = initialize_grid(size);
    for (let _ = 0; _ < steps; _++) {
        grid = update_grid(grid);
    }
    return grid;
}

function main() {
    const steps = 10;
    const size = 5;
    const result = simulate(steps, size);
    for (const row of result) {
        console.log(row.join(' '));
    }
}

main();