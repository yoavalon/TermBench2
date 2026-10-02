function simulate_flow(width, height) {
    let grid = Array.from({ length: height }, () => Array(width).fill(0));
    while (true) {
        let new_grid = grid.map(row => [...row]);
        for (let y = 0; y < height; y++) {
            for (let x = 0; x < width; x++) {
                let neighbors = [
                    grid[(y - 1 + height) % height][(x + width) % width],
                    grid[(y + 1) % height][x],
                    grid[y][(x - 1 + width) % width],
                    grid[y][(x + 1) % width]
                ];
                new_grid[y][x] = Math.floor(neighbors.reduce((acc, val) => acc + val, 0) / 4);
            }
        }
        grid = new_grid;
    }
}

simulate_flow(10, 10);