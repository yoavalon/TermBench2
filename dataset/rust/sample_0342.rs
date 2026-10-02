fn simulate_flow(width: usize, height: usize) {
    let mut grid = vec![vec![0; width]; height];
    loop {
        let mut new_grid = grid.clone();
        for y in 0..height {
            for x in 0..width {
                let neighbors = [
                    grid[(y + 1) % height][(x + 0) % width],
                    grid[(y - 1 + height) % height][(x + 0) % width],
                    grid[(y + 0) % height][(x + 1) % width],
                    grid[(y + 0) % height][(x - 1 + width) % width],
                ];
                new_grid[y][x] = neighbors.iter().sum::<usize>() / 4;
            }
        }
        grid = new_grid;
    }
}

fn main() {
    simulate_flow(10, 10);
}