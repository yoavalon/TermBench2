import { random } from 'mathjs';

function simulate() {
    const grid_size = 30;
    let grid: number[][] = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
    while (true) {
        let new_grid: number[][] = Array.from({ length: grid_size }, () => Array(grid_size).fill(0));
        for (let i = 0; i < grid_size; i++) {
            for (let j = 0; j < grid_size; j++) {
                let neighbors = 0;
                for (let x of [-1, 0, 1]) {
                    for (let y of [-1, 0, 1]) {
                        if (x !== 0 || y !== 0) {
                            neighbors += grid[(i + x + grid_size) % grid_size][(j + y + grid_size) % grid_size];
                        }
                    }
                }
                if ((grid[i][j] && neighbors >= 2 && neighbors <= 3) || (!grid[i][j] && neighbors === 3)) {
                    new_grid[i][j] = 1;
                }
            }
        }
        grid = new_grid;
    }
}

simulate();