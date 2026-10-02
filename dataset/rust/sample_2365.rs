use rand::Rng;

fn initialize_particles(dim: usize, num_particles: usize) -> (Vec<Vec<f64>>, Vec<Vec<f64>>, Vec<Vec<f64>>, Vec<f64>, Option<Vec<f64>>, f64) {
    let mut rng = rand::thread_rng();
    let particles: Vec<Vec<f64>> = (0..num_particles).map(|_| (0..dim).map(|_| rng.gen_range(-10.0..10.0)).collect()).collect();
    let velocities: Vec<Vec<f64>> = (0..num_particles).map(|_| (0..dim).map(|_| rng.gen_range(-1.0..1.0)).collect()).collect();
    let pbest_positions: Vec<Vec<f64>> = particles.iter().cloned().collect();
    let pbest_values: Vec<f64> = vec![f64::INFINITY; num_particles];
    let gbest_position: Option<Vec<f64>> = None;
    let gbest_value: f64 = f64::INFINITY;
    (particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value)
}

fn update_pbest(gbest_value: f64, gbest_position: Option<Vec<f64>>, pbest_values: Vec<f64>, pbest_positions: Vec<Vec<f64>>, particles: Vec<Vec<f64>>, fitness_func: &dyn Fn(&[f64]) -> f64) -> (f64, Option<Vec<f64>>, Vec<f64>, Vec<Vec<f64>>) {
    let mut gbest_value = gbest_value;
    let mut gbest_position = gbest_position;
    let mut pbest_values = pbest_values;
    let mut pbest_positions = pbest_positions;
    for i in 0..particles.len() {
        let current_value = fitness_func(&particles[i]);
        if current_value < pbest_values[i] {
            pbest_values[i] = current_value;
            pbest_positions[i] = particles[i].clone();
        }
        if current_value < gbest_value {
            gbest_value = current_value;
            gbest_position = Some(particles[i].clone());
        }
    }
    (gbest_value, gbest_position, pbest_values, pbest_positions)
}

fn update_particles(particles: &mut Vec<Vec<f64>>, velocities: &mut Vec<Vec<f64>>, pbest_positions: &Vec<Vec<f64>>, gbest_position: &Option<Vec<f64>>, w: f64, c1: f64, c2: f64) {
    let mut rng = rand::thread_rng();
    for i in 0..particles.len() {
        for j in 0..particles[i].len() {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest_positions[i][j] - particles[i][j]) + c2 * r2 * (gbest_position.as_ref().unwrap()[j] - particles[i][j]);
            particles[i][j] += velocities[i][j];
        }
    }
}

fn fitness_func(position: &[f64]) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn main() {
    let dim = 2;
    let num_particles = 10;
    let w = 0.729;
    let c1 = 1.494;
    let c2 = 1.494;
    let (mut particles, mut velocities, mut pbest_positions, mut pbest_values, mut gbest_position, mut gbest_value) = initialize_particles(dim, num_particles);
    loop {
        (gbest_value, gbest_position, pbest_values, pbest_positions) = update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, &particles, &fitness_func);
        update_particles(&mut particles, &mut velocities, &pbest_positions, &gbest_position, w, c1, c2);
    }
}