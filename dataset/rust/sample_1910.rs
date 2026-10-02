use rand::Rng;

fn update_grid(grid: &mut Vec<Vec<f32>>) {
    let rows = grid.len();
    let cols = grid[0].len();
    let mut new_grid = vec![vec![0.0; cols]; rows];

    for i in 1..rows - 1 {
        for j in 1..cols - 1 {
            let neighbors_sum: f32 = (-1..=1)
                .flat_map(|di| (-1..=1).map(move |dj| (di, dj)))
                .map(|(di, dj)| grid[i + di][j + dj])
                .sum();
            new_grid[i][j] = neighbors_sum - grid[i][j];
        }
    }

    *grid = new_grid;
}

fn simulate_flow(iterations: usize) -> Vec<Vec<f32>> {
    let mut grid: Vec<Vec<f32>> = (0..10)
        .map(|_| (0..10).map(|_| rand::random::<f32>()).collect())
        .collect();

    for _ in 0..iterations {
        update_grid(&mut grid);
    }

    grid
}

fn main() {
    let result = simulate_flow(100);
    for row in result {
        println!("{:?}", row);
    }
}