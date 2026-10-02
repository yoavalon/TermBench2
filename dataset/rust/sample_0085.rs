fn optimize(iterations: usize, particles: usize, dimensions: usize) -> Vec<f64> {
    let mut velocity = vec![vec![0.0; dimensions]; particles];
    let mut position = vec![vec![0.0; dimensions]; particles];
    let mut best_position = vec![vec![0.0; dimensions]; particles];
    let mut global_best = vec![0.0; dimensions];
    
    for _ in 0..iterations {
        for i in 0..particles {
            for j in 0..dimensions {
                velocity[i][j] = 0.5 * velocity[i][j] + 0.3 * (best_position[i][j] - position[i][j]) + 0.2 * (global_best[j] - position[i][j]);
                position[i][j] += velocity[i][j];
            }
        }
    }
    global_best
}

fn main() {
    optimize(100, 20, 3);
}