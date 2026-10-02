use rand::Rng;

fn update_velocity(particles: &mut Vec<Vec<f64>>, velocities: &mut Vec<Vec<f64>>, pbest: &Vec<Vec<f64>>, gbest: &Vec<f64>, w: f64, c1: f64, c2: f64) {
    for i in 0..particles.len() {
        for j in 0..particles[i].len() {
            let r1: f64 = rand::thread_rng().gen();
            let r2: f64 = rand::thread_rng().gen();
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest[i][j] - particles[i][j]) + c2 * r2 * (gbest[j] - particles[i][j]);
        }
    }
}

fn update_position(particles: &mut Vec<Vec<f64>>, velocities: &Vec<Vec<f64>>) {
    for i in 0..particles.len() {
        for j in 0..particles[i].len() {
            particles[i][j] += velocities[i][j];
        }
    }
}

fn optimize(particles: &mut Vec<Vec<f64>>, velocities: &mut Vec<Vec<f64>>, pbest: &Vec<Vec<f64>>, gbest: &Vec<f64>, w: f64, c1: f64, c2: f64) {
    update_velocity(particles, velocities, pbest, gbest, w, c1, c2);
    update_position(particles, velocities);
    optimize(particles, velocities, pbest, gbest, w, c1, c2);
}

fn fitness(position: &Vec<f64>) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn main() {
    let num_particles = 10;
    let dimensions = 2;
    let mut particles: Vec<Vec<f64>> = (0..num_particles).map(|_| (0..dimensions).map(|_| rand::thread_rng().gen_range(-10.0..10.0)).collect()).collect();
    let mut velocities: Vec<Vec<f64>> = (0..num_particles).map(|_| (0..dimensions).map(|_| rand::thread_rng().gen_range(-1.0..1.0)).collect()).collect();
    let pbest = particles.clone();
    let gbest = particles.iter().min_by(|a, b| fitness(a).partial_cmp(&fitness(b)).unwrap()).unwrap().clone();
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    optimize(&mut particles, &mut velocities, &pbest, &gbest, w, c1, c2);
}