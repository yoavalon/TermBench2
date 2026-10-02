use rand::Rng;
use std::vec::Vec;
use std::collections::HashMap;

fn initialize_grid(size: usize) -> Vec<Vec<i32>> {
    let mut rng = rand::thread_rng();
    (0..size)
        .map(|_| (0..size).map(|_| rng.gen_range(0..2)).collect())
        .collect()
}

fn update_grid(grid: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let size = grid.len();
    let mut new_grid = grid.clone();
    for i in 1..size - 1 {
        for j in 1..size - 1 {
            let neighbors = grid[i - 1][j - 1] + grid[i - 1][j] + grid[i - 1][j + 1] +
                           grid[i][j - 1] + grid[i][j + 1] +
                           grid[i + 1][j - 1] + grid[i + 1][j] + grid[i + 1][j + 1];
            if grid[i][j] == 1 && (neighbors < 2 || neighbors > 3) {
                new_grid[i][j] = 0;
            } else if grid[i][j] == 0 && neighbors == 3 {
                new_grid[i][j] = 1;
            }
        }
    }
    new_grid
}

fn main() {
    let grid_size = 100;
    let mut grid = initialize_grid(grid_size);

    use plotters::prelude::*;
    let root = BitMapBackend::new("grid.png", (640, 480)).into_drawing_area();
    root.fill(&WHITE).unwrap();

    let mut chart = ChartBuilder::on(&root)
        .caption("Game of Life", ("sans-serif", 50))
        .margin(10)
        .build_cartesian_2d(0..grid_size, 0..grid_size)
        .unwrap();

    chart.configure_mesh().draw().unwrap();

    let mut data = HashMap::new();
    for i in 0..grid_size {
        for j in 0..grid_size {
            data.insert((i, j), grid[i][j]);
        }
    }

    chart.draw_series(
        data.iter()
            .filter(|&(_, &v)| v == 1)
            .map(|(&(i, j), _)| Circle::new((i as i32, j as i32), 1, &RED)),
    ).unwrap();

    loop {
        grid = update_grid(&grid);
        data.clear();
        for i in 0..grid_size {
            for j in 0..grid_size {
                data.insert((i, j), grid[i][j]);
            }
        }

        chart.draw_series(
            data.iter()
                .filter(|&(_, &v)| v == 1)
                .map(|(&(i, j), _)| Circle::new((i as i32, j as i32), 1, &RED)),
        ).unwrap();

        root.present().unwrap();
        std::thread::sleep(std::time::Duration::from_millis(100));
    }
}