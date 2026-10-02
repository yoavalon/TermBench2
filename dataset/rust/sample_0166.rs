use rand::Rng;

fn initialize_particles(num_particles: usize, dimensions: usize, bounds: (f64, f64)) -> Vec<Vec<f64>> {
    let mut rng = rand::thread_rng();
    let mut particles = Vec::with_capacity(num_particles);
    for _ in 0..num_particles {
        let particle: Vec<f64> = (0..dimensions)
            .map(|_| rng.gen_range(bounds.0..=bounds.1))
            .collect();
        particles.push(particle);
    }
    particles
}

fn update_positions(particles: &[Vec<f64>], velocities: &[Vec<f64>], bounds: (f64, f64)) -> Vec<Vec<f64>> {
    let mut new_positions = Vec::with_capacity(particles.len());
    for i in 0..particles.len() {
        let new_position: Vec<f64> = particles[i]
            .iter()
            .zip(velocities[i].iter())
            .map(|(&p, &v)| p.min(bounds.1).max(bounds.0 + v))
            .collect();
        new_positions.push(new_position);
    }
    new_positions
}

fn main() {
    let num_particles = 30;
    let dimensions = 2;
    let bounds = (0.0, 10.0);
    let mut particles = initialize_particles(num_particles, dimensions, bounds);
    let velocities: Vec<Vec<f64>> = (0..num_particles)
        .map(|_| (0..dimensions).map(|_| rand::thread_rng().gen_range(-1.0..=1.0)).collect())
        .collect();
    for _ in 0..100 {
        particles = update_positions(&particles, &velocities, bounds);
    }
    println!("{:?}", particles);
}