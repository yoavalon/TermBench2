use rand::Rng;

fn fitness_function(x: f64) -> f64 {
    x.powi(2)
}

fn update_position(position: f64, velocity: f64, w: f64, c1: f64, c2: f64, pbest: f64, gbest: f64) -> (f64, f64) {
    let r1: f64 = rand::thread_rng().gen();
    let r2: f64 = rand::thread_rng().gen();
    let velocity = w * velocity + c1 * r1 * (pbest - position) + c2 * r2 * (gbest - position);
    let position = position + velocity;
    (position, velocity)
}

fn optimize(iterations: usize, w: f64, c1: f64, c2: f64, bounds: (f64, f64)) -> f64 {
    let mut particles: Vec<f64> = (0..30).map(|_| rand::thread_rng().gen_range(bounds.0..=bounds.1)).collect();
    let mut velocities: Vec<f64> = vec![0.0; 30];
    let mut pbests: Vec<f64> = particles.clone();
    let mut gbest = *particles.iter().min_by(|a, b| fitness_function(*a).partial_cmp(&fitness_function(*b)).unwrap()).unwrap();

    for _ in 0..iterations {
        for i in 0..particles.len() {
            let (new_position, new_velocity) = update_position(particles[i], velocities[i], w, c1, c2, pbests[i], gbest);
            particles[i] = new_position;
            velocities[i] = new_velocity;
            if fitness_function(particles[i]) < fitness_function(pbests[i]) {
                pbests[i] = particles[i];
            }
        }
        gbest = *particles.iter().min_by(|a, b| fitness_function(*a).partial_cmp(&fitness_function(*b)).unwrap()).unwrap();
    }
    gbest
}

fn main() {
    let iterations = 100;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let bounds = (-10.0, 10.0);
    let result = optimize(iterations, w, c1, c2, bounds);
    println!("{}", result);
}