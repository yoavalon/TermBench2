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
    const new_grid: number[][] = JSON.parse(JSON.stringify(grid));
    const size = grid.length;
    for (let i = 1; i < size - 1; i++) {
        for (let j = 1; j < size - 1; j++) {
            let neighbors = 0;
            for (let di = -1; di <= 1; di++) {
                for (let dj = -1; dj <= 1; dj++) {
                    neighbors += grid[i + di][j + dj];
                }
            }
            neighbors -= grid[i][j];
            if (grid[i][j] === 1 && (neighbors < 2 || neighbors > 3)) {
                new_grid[i][j] = 0;
            } else if (grid[i][j] === 0 && neighbors === 3) {
                new_grid[i][j] = 1;
            }
        }
    }
    return new_grid;
}

async function main() {
    const grid_size = 100;
    let grid = initialize_grid(grid_size);
    const { createCanvas, loadImage } = await import('canvas');
    const canvas = createCanvas(grid_size, grid_size);
    const ctx = canvas.getContext('2d');
    while (true) {
        grid = update_grid(grid);
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        for (let i = 0; i < grid_size; i++) {
            for (let j = 0; j < grid_size; j++) {
                ctx.fillStyle = grid[i][j] === 1 ? 'black' : 'white';
                ctx.fillRect(j, i, 1, 1);
            }
        }
        await new Promise(resolve => setTimeout(resolve, 100));
    }
}

main();