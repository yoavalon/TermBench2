use rand::Rng;

fn update_velocity(p: f64, g: f64, v: f64, w: f64, c1: f64, c2: f64) -> f64 {
    let r1: f64 = rand::thread_rng().gen();
    let r2: f64 = rand::thread_rng().gen();
    w * v + c1 * r1 * (p - g) + c2 * r2 * (p - p)
}

fn update_position(p: f64, v: f64) -> f64 {
    p + v
}

fn optimize(particles: Vec<f64>, velocities: Vec<f64>, best_positions: Vec<f64>, global_best: f64, w: f64, c1: f64, c2: f64) -> (Vec<f64>, Vec<f64>, Vec<f64>) {
    let mut new_particles = Vec::new();
    let mut new_velocities = Vec::new();
    let mut new_best_positions = Vec::new();
    for i in 0..particles.len() {
        let v = update_velocity(particles[i], global_best, velocities[i], w, c1, c2);
        let p = update_position(particles[i], v);
        new_particles.push(p);
        new_velocities.push(v);
        if p < best_positions[i] {
            new_best_positions.push(p);
        } else {
            new_best_positions.push(best_positions[i]);
        }
    }
    (new_particles, new_velocities, new_best_positions)
}

fn swarm() {
    let mut particles: Vec<f64> = (0..10).map(|_| rand::thread_rng().gen()).collect();
    let mut velocities: Vec<f64> = (0..10).map(|_| rand::thread_rng().gen()).collect();
    let mut best_positions = particles.clone();
    let mut global_best = *best_positions.iter().min_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    loop {
        let (new_particles, new_velocities, new_best_positions) = optimize(particles.clone(), velocities.clone(), best_positions.clone(), global_best, w, c1, c2);
        particles = new_particles;
        velocities = new_velocities;
        best_positions = new_best_positions;
        global_best = *best_positions.iter().min_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
    }
}

fn main() {
    swarm();
}