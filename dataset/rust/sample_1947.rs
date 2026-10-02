fn update_grid(grid: Vec<Vec<f64>>, width: usize, height: usize) -> Vec<Vec<f64>> {
    let mut new_grid = vec![vec![0.0; width]; height];
    for y in 0..height {
        for x in 0..width {
            let mut neighbors = Vec::new();
            for dy in -1..=1 {
                for dx in -1..=1 {
                    if dy != 0 || dx != 0 {
                        neighbors.push(grid[(y + dy + height) % height][(x + dx + width) % width]);
                    }
                }
            }
            new_grid[y][x] = neighbors.iter().sum::<f64>() / neighbors.len() as f64;
        }
    }
    new_grid
}

fn simulate(width: usize, height: usize, steps: usize) -> Vec<Vec<f64>> {
    let mut grid = vec![vec![0.0; width]; height];
    for y in 0..height {
        for x in 0..width {
            grid[y][x] = (x + y) as f64;
        }
    }
    for _ in 0..steps {
        grid = update_grid(grid, width, height);
    }
    grid
}

fn main() {
    let width = 10;
    let height = 10;
    let steps = 5;
    let final_grid = simulate(width, height, steps);
    for row in final_grid {
        println!("{:?}", row);
    }
}