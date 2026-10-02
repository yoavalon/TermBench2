function update_state(grid: number[][], width: number, height: number): number[][] {
    const new_grid: number[][] = Array.from({ length: height }, () => Array(width).fill(0));
    for (let y = 0; y < height; y++) {
        for (let x = 0; x < width; x++) {
            let neighbors = 0;
            for (let dy of [-1, 0, 1]) {
                for (let dx of [-1, 0, 1]) {
                    if (dy === 0 && dx === 0) continue;
                    const nx = x + dx;
                    const ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        neighbors += grid[ny][nx];
                    }
                }
            }
            if (grid[y][x] === 1) {
                new_grid[y][x] = (neighbors >= 2 && neighbors <= 3) ? 1 : 0;
            } else {
                new_grid[y][x] = (neighbors === 3) ? 1 : 0;
            }
        }
    }
    return new_grid;
}

function simulate(grid: number[][], width: number, height: number, steps: number): number[][] {
    if (steps === 0) {
        return grid;
    } else {
        return simulate(update_state(grid, width, height), width, height, steps - 1);
    }
}

function main() {
    const width = 50;
    const height = 50;
    const steps = 100;
    const grid: number[][] = Array.from({ length: height }, (_, y) => Array.from({ length: width }, (_, x) => (x + y) % 2 ? 1 : 0));
    const final_grid = simulate(grid, width, height, steps);
    for (const row of final_grid) {
        console.log(row.map(cell => cell ? 'O' : ' ').join(''));
    }
}

main();