struct FluidCell {
    x: i32,
    y: i32,
    pressure: f64,
    velocity: (f64, f64),
}

impl FluidCell {
    fn new(x: i32, y: i32) -> FluidCell {
        FluidCell {
            x,
            y,
            pressure: 0.0,
            velocity: (0.0, 0.0),
        }
    }

    fn update_pressure(&mut self, neighbors: &Vec<&FluidCell>) {
        let mut total_pressure = 0.0;
        for cell in neighbors {
            total_pressure += cell.pressure;
        }
        self.pressure = total_pressure / neighbors.len() as f64;
    }

    fn update_velocity(&mut self, neighbors: &Vec<&FluidCell>) {
        let mut dx = 0.0;
        let mut dy = 0.0;
        for cell in neighbors {
            dx += cell.velocity.0;
            dy += cell.velocity.1;
        }
        self.velocity = (dx / neighbors.len() as f64, dy / neighbors.len() as f64);
    }
}

fn get_neighbors(grid: &Vec<Vec<FluidCell>>, x: i32, y: i32) -> Vec<&FluidCell> {
    let mut neighbors = Vec::new();
    let directions = [(-1, 0), (1, 0), (0, -1), (0, 1)];
    for &(dx, dy) in &directions {
        let nx = x + dx;
        let ny = y + dy;
        if nx >= 0 && nx < grid.len() as i32 && ny >= 0 && ny < grid[0].len() as i32 {
            neighbors.push(&grid[nx as usize][ny as usize]);
        }
    }
    neighbors
}

fn simulate(grid: &mut Vec<Vec<FluidCell>>) {
    loop {
        for row in grid.iter_mut() {
            for cell in row.iter_mut() {
                let neighbors = get_neighbors(grid, cell.x, cell.y);
                cell.update_pressure(&neighbors);
                cell.update_velocity(&neighbors);
            }
        }
    }
}

fn main() {
    let width = 10;
    let height = 10;
    let mut grid: Vec<Vec<FluidCell>> = (0..width)
        .map(|x| (0..height).map(|y| FluidCell::new(x, y)).collect())
        .collect();
    simulate(&mut grid);
}