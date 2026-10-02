function simulate_flow(width: number, height: number): void {
    let grid: number[][] = Array.from({ length: height }, () => Array(width).fill(0));
    while (true) {
        let new_grid: number[][] = grid.map(row => [...row]);
        for (let y = 0; y < height; y++) {
            for (let x = 0; x < width; x++) {
                let neighbors: number[] = [
                    grid[(y - 1 + height) % height][(x - 1 + width) % width],
                    grid[(y - 1 + height) % height][x % width],
                    grid[(y - 1 + height) % height][(x + 1) % width],
                    grid[y % height][(x - 1 + width) % width],
                    grid[y % height][(x + 1) % width],
                    grid[(y + 1) % height][(x - 1 + width) % width],
                    grid[(y + 1) % height][x % width],
                    grid[(y + 1) % height][(x + 1) % width]
                ];
                new_grid[y][x] = Math.floor(neighbors.reduce((sum, val) => sum + val, 0) / 4);
            }
        }
        grid = new_grid;
    }
}

simulate_flow(10, 10);